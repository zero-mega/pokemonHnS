#!/usr/bin/env python3
"""
Fetch French UI strings from pokeemerald-fr repository and update ui_strings.csv
"""
import csv
import re
import sys
from pathlib import Path

import requests

REPO_ROOT = Path(__file__).resolve().parents[1]
UI_STRINGS_CSV = REPO_ROOT / 'localization' / 'fr' / 'templates' / 'ui_strings.csv'

# French strings.c from pokeemerald-fr repository
FR_STRINGS_URL = 'https://raw.githubusercontent.com/simsor/pokeemerald-fr/french/src/strings.c'

def fetch_french_strings():
    """Fetch and parse French strings from pokeemerald-fr repository."""
    print(f'Fetching French strings from {FR_STRINGS_URL}...')
    try:
        resp = requests.get(FR_STRINGS_URL, timeout=30)
        resp.raise_for_status()
        text = resp.text
    except requests.RequestException as e:
        print(f'Error fetching French strings: {e}')
        sys.exit(1)
    
    print('Parsing French translations...')
    # Pattern to match: const u8 gText_Something[] = _("French text");
    # Handle multi-line strings too
    pattern = re.compile(r'const u8 (gText_[A-Za-z0-9_]+)\[\] = _\(\"([\s\S]*?)\"\);')
    
    translations = {}
    for match in pattern.finditer(text):
        key = match.group(1)
        value = match.group(2)
        # Clean up the value - handle escaped quotes and newlines
        value = value.replace('\\n', '\n').replace('\\"', '"')
        translations[key] = value
    
    print(f'Found {len(translations)} French translations')
    return translations

def update_ui_strings_csv(fr_translations):
    """Update ui_strings.csv with French translations."""
    if not UI_STRINGS_CSV.exists():
        print(f'Error: {UI_STRINGS_CSV} does not exist')
        sys.exit(1)
    
    print(f'Reading {UI_STRINGS_CSV}...')
    rows = []
    with UI_STRINGS_CSV.open('r', encoding='utf-8', newline='') as f:
        reader = csv.DictReader(f)
        for row in reader:
            rows.append(row)
    
    print(f'Updating {len(rows)} rows with French translations...')
    updated_count = 0
    missing_count = 0
    
    for row in rows:
        key = row['key']
        if key in fr_translations:
            # Replace newlines with \n for CSV storage
            fr_text = fr_translations[key].replace('\n', '\\n')
            row['text'] = fr_text
            updated_count += 1
        else:
            missing_count += 1
            if missing_count <= 10:  # Only print first 10 missing keys
                print(f'  Warning: No French translation found for {key}')
    
    print(f'Writing updated CSV...')
    with UI_STRINGS_CSV.open('w', encoding='utf-8', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=['key', 'text'])
        writer.writeheader()
        writer.writerows(rows)
    
    print(f'\nSuccess!')
    print(f'  Updated: {updated_count} strings')
    print(f'  Missing: {missing_count} strings')
    if missing_count > 10:
        print(f'  (only showed first 10 missing keys)')

def main():
    print('=' * 60)
    print('Fetching French UI strings from pokeemerald-fr')
    print('=' * 60)
    print()
    
    fr_translations = fetch_french_strings()
    update_ui_strings_csv(fr_translations)
    
    print()
    print('Done! You can now apply the translations using:')
    print('  python tools/translate.py apply')

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        print('\nAborted by user')
        sys.exit(1)

