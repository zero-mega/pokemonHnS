#!/usr/bin/env python3
import argparse
import csv
import re
import sys
from pathlib import Path

# Minimal scaffold: validates CSV presence and prints next steps.

REPO_ROOT = Path(__file__).resolve().parents[1]
TEMPLATES_DIR = REPO_ROOT / 'localization' / 'fr' / 'templates'

CSV_EXPECTED = [
    'species.csv', 'moves.csv', 'move_descriptions.csv',
    'items.csv', 'item_descriptions.csv',
    'abilities.csv', 'ability_descriptions.csv',
    'natures.csv', 'types.csv',
    'ui_strings.csv', 'scripts.csv',
    'map_sections.csv', 'easy_chat.csv',
]

def read_csv(path: Path):
    with path.open(newline='', encoding='utf-8') as f:
        return list(csv.DictReader(f))

SPECIES_FILE = REPO_ROOT / 'src' / 'data' / 'text' / 'species_names.h'
MOVES_FILE = REPO_ROOT / 'src' / 'data' / 'text' / 'move_names.h'
ABILITIES_FILE = REPO_ROOT / 'src' / 'data' / 'text' / 'abilities.h'
NATURES_FILE = REPO_ROOT / 'src' / 'data' / 'text' / 'nature_names.h'
TYPES_FILE = REPO_ROOT / 'src' / 'battle_main.c'
MOVE_DESCRIPTIONS_FILE = REPO_ROOT / 'src' / 'data' / 'text' / 'move_descriptions.h'
ITEMS_FILE = REPO_ROOT / 'src' / 'data' / 'items.h'
ITEM_DESCRIPTIONS_FILE = REPO_ROOT / 'src' / 'data' / 'text' / 'item_descriptions.h'
STRINGS_FILE = REPO_ROOT / 'src' / 'strings.c'
MAP_SECTIONS_JSON = REPO_ROOT / 'src' / 'data' / 'region_map' / 'region_map_sections.json'

def export_species(csv_path: Path):
    data = []
    pat = re.compile(r"\[(SPECIES_[A-Z0-9_]+)\]\s*=\s*_\(\"([^\"]*)\"\)")
    for line in SPECIES_FILE.read_text(encoding='utf-8', errors='ignore').splitlines():
        m = pat.search(line)
        if m:
            data.append({'id': m.group(1), 'name': m.group(2)})
    write_csv(csv_path, ['id','name'], data)

def export_moves(csv_path: Path):
    data = []
    pat = re.compile(r"\[(MOVE_[A-Z0-9_]+)\]\s*=\s*_\(\"([^\"]*)\"\)")
    for line in MOVES_FILE.read_text(encoding='utf-8', errors='ignore').splitlines():
        m = pat.search(line)
        if m:
            data.append({'id': m.group(1), 'name': m.group(2)})
    write_csv(csv_path, ['id','name'], data)

def export_abilities(csv_path: Path):
    data = []
    pat = re.compile(r"\[(ABILITY_[A-Z0-9_]+)\]\s*=\s*_\(\"([^\"]*)\"\)")
    for line in ABILITIES_FILE.read_text(encoding='utf-8', errors='ignore').splitlines():
        m = pat.search(line)
        if m:
            data.append({'id': m.group(1), 'name': m.group(2)})
    write_csv(csv_path, ['id','name'], data)

def export_natures(csv_path: Path):
    text = NATURES_FILE.read_text(encoding='utf-8', errors='ignore')
    pat_decl = re.compile(r"static const u8 s([A-Za-z]+)NatureName\[\] = _\(\"([^\"]*)\"\);")
    pat_map = re.compile(r"\[NATURE_([A-Z_]+)\]\s*=\s*s([A-Za-z]+)NatureName")
    var_to_name = {m.group(1): m.group(2) for m in pat_decl.finditer(text)}
    rows = []
    for m in pat_map.finditer(text):
        key = m.group(1)
        var = m.group(2)
        name = var_to_name.get(var, '')
        rows.append({'id': f'NATURE_{key}', 'name': name})
    write_csv(csv_path, ['id','name'], rows)

def export_types(csv_path: Path):
    data = []
    capture = False
    for line in TYPES_FILE.read_text(encoding='utf-8', errors='ignore').splitlines():
        if 'const u8 gTypeNames' in line:
            capture = True
            continue
        if capture and '};' in line:
            break
        if capture:
            m = re.search(r"\[TYPE_([A-Z_]+)\]\s*=\s*_\(\"([^\"]*)\"\)", line)
            if m:
                data.append({'id': f'TYPE_{m.group(1)}', 'name': m.group(2)})
    write_csv(csv_path, ['id','name'], data)

def export_move_descriptions(csv_path: Path):
    text = MOVE_DESCRIPTIONS_FILE.read_text(encoding='utf-8', errors='ignore')
    # description var -> text
    desc_vars = {}
    for m in re.finditer(r"static const u8 (s[A-Za-z0-9_]+Description)\[\] = _\(\n?\s*\"([\s\S]*?)\"\);", text):
        var, val = m.group(1), m.group(2)
        val = val.replace("\r", "").replace("\n\n", "\\n").replace("\n", "\\n")
        desc_vars[var] = val
    rows = []
    for m in re.finditer(r"\[(MOVE_[A-Z0-9_]+)\s*-\s*1\]\s*=\s*(s[A-Za-z0-9_]+Description)", text):
        move_id, var = m.group(1), m.group(2)
        rows.append({'id': move_id, 'description': desc_vars.get(var, '')})
    write_csv(csv_path, ['id','description'], rows)

def export_items(csv_items: Path, csv_item_desc: Path):
    desc_text = ITEM_DESCRIPTIONS_FILE.read_text(encoding='utf-8', errors='ignore')
    desc_vars = {}
    for m in re.finditer(r"static const u8 (sItemDesc_[A-Za-z0-9_]+)\[\] = _\(\n?\s*\"([\s\S]*?)\"\);", desc_text):
        desc_vars[m.group(1)] = m.group(2).replace("\r", "").replace("\n\n", "\\n").replace("\n", "\\n")
    rows_names = []
    rows_descs = []
    block_re = re.compile(r"\[(ITEM_[A-Z0-9_]+)\]\s*=\s*\{([\s\S]*?)\}\,", re.M)
    name_re = re.compile(r"\.name\s*=\s*_\(\"([^\"]*)\"\)")
    desc_re = re.compile(r"\.description\s*=\s*([A-Za-z0-9_]+)")
    items_text = ITEMS_FILE.read_text(encoding='utf-8', errors='ignore')
    for m in block_re.finditer(items_text):
        item_id, body = m.group(1), m.group(2)
        name_m = name_re.search(body)
        if name_m:
            rows_names.append({'id': item_id, 'name': name_m.group(1)})
        desc_m = desc_re.search(body)
        if desc_m:
            var = desc_m.group(1)
            val = desc_vars.get(var, '')
            rows_descs.append({'id': item_id, 'description': val})
    write_csv(csv_items, ['id','name'], rows_names)
    write_csv(csv_item_desc, ['id','description'], rows_descs)

def export_ui_strings(csv_path: Path):
    rows = []
    try:
        text = STRINGS_FILE.read_text(encoding='utf-8', errors='ignore')
    except FileNotFoundError:
        write_csv(csv_path, ['key','text'], rows)
        return
    pat = re.compile(r"const u8 (gText_[A-Za-z0-9_]+)\[\] = _\(\"([\s\S]*?)\"\);")
    for m in pat.finditer(text):
        key, val = m.group(1), m.group(2)
        val = val.replace("\r", "").replace("\n\n", "\\n").replace("\n", "\\n")
        rows.append({'key': key, 'text': val})
    write_csv(csv_path, ['key','text'], rows)

def export_map_sections(csv_path: Path):
    rows = []
    if MAP_SECTIONS_JSON.exists():
        try:
            import json
            data = json.loads(MAP_SECTIONS_JSON.read_text(encoding='utf-8', errors='ignore'))
            # The JSON has 'map_sections' array with 'map_section' (id) and 'name' keys
            sections = data.get('map_sections', [])
            for entry in sections:
                rows.append({'id': entry.get('map_section', ''), 'name': entry.get('name', '')})
        except Exception as e:
            print(f"Warning: Failed to export map sections: {e}")
    write_csv(csv_path, ['id','name'], rows)

def export_easy_chat(csv_path: Path):
    """Export all Easy Chat words from the various group files."""
    rows = []
    easy_chat_dir = REPO_ROOT / 'src' / 'data' / 'easy_chat'
    
    # Map of group file names to their group identifiers
    group_files = [
        ('easy_chat_group_people.h', 'EC_GROUP_PEOPLE'),
        ('easy_chat_group_battle.h', 'EC_GROUP_BATTLE'),
        ('easy_chat_group_greetings.h', 'EC_GROUP_GREETINGS'),
        ('easy_chat_group_voices.h', 'EC_GROUP_VOICES'),
        ('easy_chat_group_speech.h', 'EC_GROUP_SPEECH'),
        ('easy_chat_group_endings.h', 'EC_GROUP_ENDINGS'),
        ('easy_chat_group_feelings.h', 'EC_GROUP_FEELINGS'),
        ('easy_chat_group_conditions.h', 'EC_GROUP_CONDITIONS'),
        ('easy_chat_group_actions.h', 'EC_GROUP_ACTIONS'),
        ('easy_chat_group_lifestyle.h', 'EC_GROUP_LIFESTYLE'),
        ('easy_chat_group_hobbies.h', 'EC_GROUP_HOBBIES'),
        ('easy_chat_group_time.h', 'EC_GROUP_TIME'),
        ('easy_chat_group_misc.h', 'EC_GROUP_MISC'),
        ('easy_chat_group_adjectives.h', 'EC_GROUP_ADJECTIVES'),
        ('easy_chat_group_events.h', 'EC_GROUP_EVENTS'),
        ('easy_chat_group_move_1.h', 'EC_GROUP_MOVE_1'),
        ('easy_chat_group_move_2.h', 'EC_GROUP_MOVE_2'),
        ('easy_chat_group_trainer.h', 'EC_GROUP_TRAINER'),
        ('easy_chat_group_status.h', 'EC_GROUP_STATUS'),
        ('easy_chat_group_trendy_saying.h', 'EC_GROUP_TRENDY_SAYING'),
    ]
    
    # Pattern to match word definitions: const u8 gEasyChatWord_XYZ[] = _("TEXT");
    pat = re.compile(r"const u8 gEasyChatWord_([A-Za-z0-9_]+)\[\] = _\(\"([^\"]*)\"\);")
    
    for filename, group in group_files:
        filepath = easy_chat_dir / filename
        if filepath.exists():
            try:
                text = filepath.read_text(encoding='utf-8', errors='ignore')
                for m in pat.finditer(text):
                    key, text_val = m.group(1), m.group(2)
                    rows.append({'group': group, 'key': key, 'text': text_val})
            except Exception as e:
                print(f"Warning: Failed to read {filename}: {e}")
    
    write_csv(csv_path, ['group','key','text'], rows)

def export_scripts(csv_path: Path):
    """Export script text. This is a placeholder - scripts are complex and spread across many files."""
    # For now, just create an empty template with the right structure
    # Real implementation would need to parse data/text/*.inc files
    rows = []
    # Could potentially scan data/text/*.inc files, but they're complex
    # and have various formats. Leave as placeholder for manual population.
    write_csv(csv_path, ['key','text'], rows)
    print("Note: scripts.csv export is a placeholder. Script text is in data/text/*.inc files.")

def write_csv(path: Path, fieldnames, rows):
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open('w', newline='', encoding='utf-8') as f:
        w = csv.DictWriter(f, fieldnames=fieldnames)
        w.writeheader()
        for r in rows:
            w.writerow(r)

def apply_species(csv_path: Path):
    rows = {r['id']: r['name'] for r in read_csv(csv_path)}
    pat = re.compile(r"(\[(SPECIES_[A-Z0-9_]+)\]\s*=\s*_\(\")([^\"]*)(\"\))")
    def repl(m):
        key = m.group(2)
        new = rows.get(key, m.group(3))
        return f"[{key}] = _(\"{new}\")"
    text = SPECIES_FILE.read_text(encoding='utf-8', errors='ignore')
    text = re.sub(pat, lambda m: repl(m), text)
    SPECIES_FILE.write_text(text, encoding='utf-8')

def apply_moves(csv_path: Path):
    rows = {r['id']: r['name'] for r in read_csv(csv_path)}
    pat = re.compile(r"(\[(MOVE_[A-Z0-9_]+)\]\s*=\s*_\(\")([^\"]*)(\"\))")
    def repl(m):
        key = m.group(2)
        new = rows.get(key, m.group(3))
        return f"[{key}] = _(\"{new}\")"
    text = MOVES_FILE.read_text(encoding='utf-8', errors='ignore')
    text = re.sub(pat, lambda m: repl(m), text)
    MOVES_FILE.write_text(text, encoding='utf-8')

def apply_abilities(csv_path: Path):
    rows = {r['id']: r['name'] for r in read_csv(csv_path)}
    pat = re.compile(r"(\[(ABILITY_[A-Z0-9_]+)\]\s*=\s*_\(\")([^\"]*)(\"\))")
    def repl(m):
        key = m.group(2)
        new = rows.get(key, m.group(3))
        return f"[{key}] = _(\"{new}\")"
    text = ABILITIES_FILE.read_text(encoding='utf-8', errors='ignore')
    text = re.sub(pat, lambda m: repl(m), text)
    ABILITIES_FILE.write_text(text, encoding='utf-8')

def apply_natures(csv_path: Path):
    rows = {r['id']: r['name'] for r in read_csv(csv_path)}
    # Update declarations based on pointer map to keep ordering
    text = NATURES_FILE.read_text(encoding='utf-8', errors='ignore')
    pat_decl = re.compile(r"static const u8 s([A-Za-z]+)NatureName\[\] = _\(\"([^\"]*)\"\);")
    pat_map = re.compile(r"\[NATURE_([A-Z_]+)\]\s*=\s*s([A-Za-z]+)NatureName")
    var_for_id = {f"NATURE_{m.group(1)}": m.group(2) for m in pat_map.finditer(text)}
    def repl(m):
        var = m.group(1)
        current = m.group(2)
        # find which id uses this var
        target_id = next((k for k,v in var_for_id.items() if v == var), None)
        new = rows.get(target_id, current)
        return f'static const u8 s{var}NatureName[] = _("{new}");'
    text = re.sub(pat_decl, lambda m: repl(m), text)
    NATURES_FILE.write_text(text, encoding='utf-8')

def apply_types(csv_path: Path):
    rows = {r['id']: r['name'] for r in read_csv(csv_path)}
    lines = TYPES_FILE.read_text(encoding='utf-8', errors='ignore').splitlines()
    out = []
    pat = re.compile(r"(\[TYPE_([A-Z_]+)\]\s*=\s*_\(\")([^\"]*)(\"\),?)")
    for line in lines:
        m = pat.search(line)
        if m:
            key = f'TYPE_{m.group(2)}'
            new = rows.get(key, m.group(3))
            line = pat.sub(lambda _m: f"[{key}] = _(\"{new}\"){',' if line.strip().endswith(',') else ''}", line)
        out.append(line)
    TYPES_FILE.write_text("\n".join(out), encoding='utf-8')

# ---- Auto-translate (rule-based) ----
PLACEHOLDER_RE = re.compile(r"\{[^}]*\}")

GLOSSARY = {
    'POKéMON': 'POKÉMON',
    'POKéDEX': 'POKÉDEX',
    'BAG': 'SAC',
    'SAVE': 'SAUVER',
    'OPTION': 'OPTIONS',
    'EXIT': 'QUITTER',
    'YES': 'OUI',
    'NO': 'NON',
    'HP': 'PV',
    'ATTACK': 'ATTAQUE',
    'DEFENSE': 'DEFENSE',
    'SP. ATK': 'ATQ. SPÉ',
    'SP. DEF': 'DEF. SPÉ',
    'SPEED': 'VITESSE',
    'BATTLE': 'COMBAT',
    'ITEM': 'OBJET',
    'ITEMS': 'OBJETS',
    'KEY ITEMS': 'OBJETS RARES',
    'POKé BALLS': 'POKÉ BALLS',
    'TMs & HMs': 'CT & CS',
    'CANCEL': 'ANNULER',
    'REGISTER': 'ENREGISTRER',
    'OK': 'OK',
}

PHRASES = [
    ('Press the A Button', 'Appuyez sur le bouton A'),
    ("Don't turn off the power", "N'éteignez pas la console"),
    ('Communication standby', 'Communication en cours'),
    ('Please wait', 'Veuillez patienter'),
    ('Game time', 'Temps de jeu'),
    ('RTC time', 'Heure RTC'),
    ('Save completed', 'Sauvegarde terminée'),
    ('Save failed', 'Échec de la sauvegarde'),
]

def translate_text_rule_based(text: str) -> str:
    parts = []
    last = 0
    for m in PLACEHOLDER_RE.finditer(text):
        seg = text[last:m.start()]
        parts.append(('t', seg))
        parts.append(('p', m.group(0)))
        last = m.end()
    parts.append(('t', text[last:]))

    def tr_segment(seg: str) -> str:
        s = seg
        for en, fr in PHRASES:
            s = s.replace(en, fr)
        for en, fr in GLOSSARY.items():
            s = s.replace(en, fr)
        return s

    out = []
    for kind, val in parts:
        if kind == 'p':
            out.append(val)
        else:
            out.append(tr_segment(val))
    return ''.join(out)

def cmd_auto_fr(which):
    if 'ui_strings' in which:
        path = TEMPLATES_DIR / 'ui_strings.csv'
        rows = read_csv(path)
        out = []
        for r in rows:
            txt = r.get('text', '')
            if txt:
                r['text'] = translate_text_rule_based(txt)
            out.append(r)
        write_csv(path, ['key','text'], out)
        print('Translated ui_strings.csv')
    if 'move_descriptions' in which:
        path = TEMPLATES_DIR / 'move_descriptions.csv'
        rows = read_csv(path)
        out = []
        for r in rows:
            d = r.get('description', '')
            if d:
                r['description'] = translate_text_rule_based(d)
            out.append(r)
        write_csv(path, ['id','description'], out)
        print('Translated move_descriptions.csv')
    if 'item_descriptions' in which:
        path = TEMPLATES_DIR / 'item_descriptions.csv'
        rows = read_csv(path)
        out = []
        for r in rows:
            d = r.get('description', '')
            if d:
                r['description'] = translate_text_rule_based(d)
            out.append(r)
        write_csv(path, ['id','description'], out)
        print('Translated item_descriptions.csv')
    return 0

def cmd_export():
    export_species(TEMPLATES_DIR / 'species.csv')
    export_moves(TEMPLATES_DIR / 'moves.csv')
    export_abilities(TEMPLATES_DIR / 'abilities.csv')
    export_natures(TEMPLATES_DIR / 'natures.csv')
    export_types(TEMPLATES_DIR / 'types.csv')
    export_move_descriptions(TEMPLATES_DIR / 'move_descriptions.csv')
    export_items(TEMPLATES_DIR / 'items.csv', TEMPLATES_DIR / 'item_descriptions.csv')
    export_ui_strings(TEMPLATES_DIR / 'ui_strings.csv')
    export_map_sections(TEMPLATES_DIR / 'map_sections.csv')
    export_easy_chat(TEMPLATES_DIR / 'easy_chat.csv')
    export_scripts(TEMPLATES_DIR / 'scripts.csv')
    print('Exported CSVs to', TEMPLATES_DIR)

def cmd_apply():
    missing = [name for name in CSV_EXPECTED if not (TEMPLATES_DIR / name).exists()]
    if missing:
        print('Missing CSV templates:', ', '.join(missing))
        print('Create them under', TEMPLATES_DIR)
        sys.exit(1)
    apply_species(TEMPLATES_DIR / 'species.csv')
    apply_moves(TEMPLATES_DIR / 'moves.csv')
    apply_abilities(TEMPLATES_DIR / 'abilities.csv')
    apply_natures(TEMPLATES_DIR / 'natures.csv')
    apply_types(TEMPLATES_DIR / 'types.csv')
    print('Applied CSVs for species, moves, abilities, natures, types')

def main():
    parser = argparse.ArgumentParser(description='French localization tools')
    sub = parser.add_subparsers(dest='cmd', required=True)
    sub.add_parser('export', help='Export current text to CSVs')
    sub.add_parser('apply', help='Apply CSVs into headers')
    p_auto = sub.add_parser('auto_fr', help='Auto-translate CSVs to French (rule-based)')
    p_auto.add_argument('--files', nargs='*', default=['ui_strings','move_descriptions','item_descriptions'])
    args = parser.parse_args()

    if args.cmd == 'export':
        return cmd_export()
    if args.cmd == 'apply':
        return cmd_apply()
    if args.cmd == 'auto_fr':
        return cmd_auto_fr(args.files)
    return 0

if __name__ == '__main__':
    raise SystemExit(main())


