## Localization Workflow (French - Gen 3)

This project supports translating all in-game text into French using CSV sources and a helper script.

### Files to translate (by category)
- Species names: `src/data/text/species_names.h`
- Move names: `src/data/text/move_names.h`
- Move descriptions: `src/data/text/move_descriptions.h`
- Item names/descriptions: `src/data/items.h`, `src/data/text/item_descriptions.h`
- Ability names/descriptions: `src/data/text/abilities.h`
- Nature names: `src/data/text/nature_names.h`
- Type names: `src/battle_main.c` (gTypeNames)
- UI strings: `src/strings.c` and scattered `gText_...`
- Scripts/dialog: `data/text/*.inc`, `data/event_scripts.s`, `data/scripts/*.inc`
- Easy Chat: `src/data/easy_chat/*`
- Region/Map names: `src/data/region_map/*`

### CSV templates
Templates live under `localization/fr/templates/`. Fill with official French (FRLG/RSE-era) content.

- species.csv: id,name
- moves.csv: id,name
- move_descriptions.csv: id,description
- items.csv: id,name
- item_descriptions.csv: id,description
- abilities.csv: id,name
- ability_descriptions.csv: id,description
- natures.csv: id,name
- types.csv: id,name (max 6 chars, charset-safe)
- ui_strings.csv: key,text
- scripts.csv: key,text (keep control codes)
- map_sections.csv: id,name
- easy_chat.csv: group,key,text

### Control codes and charset
- Preserve placeholders and control codes (e.g., `{STR_VAR_1}`, `{COLOR ...}`, `\n`).
- Only use characters present in `charmap.txt`. If you need accented characters, ensure they exist in the font and `gflib/characters.h`.

### Apply translations
1) Populate CSVs in `localization/fr/templates/`.
2) Run: `python tools/translate.py --lang fr`
   - The script will validate input and update target headers/INCs.

### Notes
- Keep within fixed lengths (e.g., type names 6 chars). The script will warn on overflow.
- For graphics-embedded text, replace assets in `graphics/**` separately (not automated yet).




