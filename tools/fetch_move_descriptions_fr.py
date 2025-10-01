#!/usr/bin/env python3
import re
import sys
from pathlib import Path

import requests

REPO_ROOT = Path(__file__).resolve().parents[1]
OUT_CSV = REPO_ROOT / 'localization' / 'fr' / 'templates' / 'move_descriptions.csv'

# URL to the French move descriptions file
GITHUB_URL = 'https://raw.githubusercontent.com/simsor/pokeemerald-fr/french/src/data/text/move_descriptions.h'

def fetch_french_descriptions():
    """Fetch the French move descriptions from GitHub"""
    print(f"Fetching French move descriptions from {GITHUB_URL}...")
    resp = requests.get(GITHUB_URL, timeout=30)
    resp.raise_for_status()
    return resp.text

def parse_move_descriptions(text: str) -> dict:
    """Parse the move descriptions from the C header file"""
    descriptions = {}
    
    # First, extract all description variables and their content
    desc_vars = {}
    # Match pattern like: static const u8 sPoundDescription[] = _("Description text");
    var_pattern = re.compile(
        r'static\s+const\s+u8\s+(s[A-Za-z0-9_]+Description)\[\]\s*=\s*_\(\s*"([^"]*)"',
        re.MULTILINE
    )
    
    for match in var_pattern.finditer(text):
        var_name = match.group(1)
        description = match.group(2)
        desc_vars[var_name] = description
    
    # Now map MOVE_* constants to their description variables
    # Pattern like: [MOVE_POUND - 1] = sPoundDescription,
    mapping_pattern = re.compile(
        r'\[(MOVE_[A-Z0-9_]+)\s*-\s*1\]\s*=\s*(s[A-Za-z0-9_]+Description)',
        re.MULTILINE
    )
    
    for match in mapping_pattern.finditer(text):
        move_id = match.group(1)
        var_name = match.group(2)
        if var_name in desc_vars:
            descriptions[move_id] = desc_vars[var_name]
    
    print(f"Found {len(descriptions)} French move descriptions")
    return descriptions

def update_csv_with_french(french_descriptions: dict):
    """Update the CSV file with French descriptions"""
    if not OUT_CSV.exists():
        print(f"Error: CSV file not found at {OUT_CSV}")
        print("Please run 'python tools/translate.py export' first")
        return False
    
    # Read the existing CSV
    import csv
    rows = []
    with OUT_CSV.open('r', encoding='utf-8', newline='') as f:
        reader = csv.DictReader(f)
        for row in reader:
            rows.append(row)
    
    # Update rows with French descriptions
    updated_count = 0
    for row in rows:
        move_id = row['id']
        if move_id in french_descriptions:
            # Convert special characters and escape sequences
            french_desc = french_descriptions[move_id]
            # Handle common escape sequences
            french_desc = french_desc.replace('\\n', '\n    """"\n    ""    ""')
            row['description'] = french_desc
            updated_count += 1
    
    # Write back to CSV
    with OUT_CSV.open('w', encoding='utf-8', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=['id', 'description'])
        writer.writeheader()
        writer.writerows(rows)
    
    print(f"Updated {updated_count} move descriptions in {OUT_CSV}")
    return True

def main():
    try:
        # Fetch the French file content
        french_text = fetch_french_descriptions()
        
        # Parse the descriptions
        french_descriptions = parse_move_descriptions(french_text)
        
        if not french_descriptions:
            print("Error: No descriptions found in the French file")
            return 1
        
        # Update the CSV
        success = update_csv_with_french(french_descriptions)
        
        if success:
            print("\nSuccess! French move descriptions have been fetched and applied.")
            print(f"Review the updated file at: {OUT_CSV}")
            return 0
        else:
            return 1
            
    except requests.RequestException as e:
        print(f"Error fetching from GitHub: {e}")
        return 1
    except Exception as e:
        print(f"Error: {e}")
        import traceback
        traceback.print_exc()
        return 1

if __name__ == '__main__':
    sys.exit(main())

