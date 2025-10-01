#!/usr/bin/env python3
import json
import re
import sys
from pathlib import Path

import requests

REPO_ROOT = Path(__file__).resolve().parents[1]
SPECIES_FILE = REPO_ROOT / 'src' / 'data' / 'text' / 'species_names.h'
OUT_CSV = REPO_ROOT / 'localization' / 'fr' / 'templates' / 'species.csv'

API_URL = 'https://tyradex.vercel.app/api/v1/pokemon'

def normalize(s: str) -> str:
    s = s.upper()
    s = s.replace("É", "E").replace("È", "E").replace("Ê", "E").replace("Ë", "E")
    s = s.replace("À", "A").replace("Â", "A").replace("Ä", "A")
    s = s.replace("Î", "I").replace("Ï", "I")
    s = s.replace("Ô", "O").replace("Ö", "O")
    s = s.replace("Û", "U").replace("Ü", "U")
    s = s.replace("Ç", "C")
    s = s.replace("'", "").replace(".", "").replace("-", " ")
    s = re.sub(r"\s+", " ", s).strip()
    return s

def load_species_pairs():
    # Parse species_names.h -> [(SPECIES_KEY, EN_NAME)]
    pairs = []
    pat = re.compile(r"\[(SPECIES_[A-Z0-9_]+)\]\s*=\s*_\(\"([^\"]*)\"\)")
    for line in SPECIES_FILE.read_text(encoding='utf-8', errors='ignore').splitlines():
        m = pat.search(line)
        if m:
            pairs.append((m.group(1), m.group(2)))
    return pairs

def build_fr_index():
    # Fetch Tyradex Pokémon list and build indices by EN/FR names
    resp = requests.get(API_URL, timeout=30)
    resp.raise_for_status()
    data = resp.json()
    en_map = {}
    fr_map = {}
    for p in data:
        name = p.get('name') or {}
        en = (name.get('en') or name.get('english') or "").upper()
        fr = (name.get('fr') or name.get('french') or "")
        if en:
            en_map[normalize(en)] = fr
        # also index by normalized FR to help some special forms
        if fr:
            fr_map[normalize(fr)] = fr
    return en_map, fr_map

def main():
    pairs = load_species_pairs()
    en_map, fr_map = build_fr_index()

    OUT_CSV.parent.mkdir(parents=True, exist_ok=True)
    with OUT_CSV.open('w', encoding='utf-8', newline='') as f:
        f.write('id,name\n')
        misses = []
        for sid, en_name in pairs:
            key = normalize(en_name)
            fr = en_map.get(key)
            if not fr:
                # Try without spaces, then raw key
                fr = en_map.get(key.replace(' ', '')) or fr_map.get(key)
            if not fr:
                misses.append((sid, en_name))
                # default to EN if miss; we'll review later
                fr = en_name.title()
            f.write(f'{sid},{fr}\n')

    if misses:
        print(f'Warning: {len(misses)} species not matched, defaulted to EN (review needed):')
        print(', '.join([m[1] for m in misses[:20]]), '...')
    else:
        print('All species matched to FR names.')

if __name__ == '__main__':
    raise SystemExit(main())




