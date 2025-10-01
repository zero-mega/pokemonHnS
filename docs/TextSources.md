## Text Sources Catalog

This document inventories all in-game text sources to support translation (species, moves, items, abilities, types, natures, UI strings, scripts/dialog, map/region names, Easy Chat, and engine text controls).

### Core Name/Description Tables
- Species names
  - `src/data/text/species_names.h` (gSpeciesNames)
- Move names and descriptions
  - `src/data/text/move_names.h` (gMoveNames)
  - `src/data/text/move_descriptions.h` (gMoveDescriptionPointers)
- Item names and descriptions
  - `src/data/items.h` (gItems: `.name`, `.description`, etc.)
  - `src/data/text/item_descriptions.h`
- Ability names and descriptions
  - `src/data/text/abilities.h` (gAbilityNames, gAbilityDescriptionPointers)
- Nature names
  - `src/data/text/nature_names.h` (gNatureNamePointers)
- Type names
  - Defined in `src/battle_main.c` (gTypeNames)
  - Referenced via `include/battle_main.h` (extern) and `include/constants/global.h` (TYPE_NAME_LENGTH)

### General UI Strings and Shared Pools
- Master string pool and externs
  - `src/strings.c` (many `gText_...` definitions)
  - `include/strings.h` (externs)
- Additional UI/string modules (examples)
  - `src/text_input_strings.c`
  - `src/data/contest_text_tables.h`
  - `src/data/battle_frontier/apprentice.h`
  - `src/data/trade.h`
  - Wireless/Union Room and system UI (e.g., `src/wireless_communication_status_screen.c`, `src/union_room_chat.c`, `src/wallclock.c`, `src/use_pokeblock.c`)

### Scripts and Dialog Text
- Script/dialog pools
  - `data/text/*.inc` (e.g., `contest_strings.inc`, `pc.inc`, `pkmn_center_nurse.inc`, `mart_clerk.inc`, `trainers.inc`, `tv.inc`, etc.)
  - `data/event_scripts.s`, `data/scripts/*.inc`
- Battle text
  - `data/battle_scripts_1.s`, `data/battle_anim_scripts.s`
  - `src/battle_message.c`, `include/battle_message.h`
- Pokedex and related views
  - `src/pokedex.c`, `src/pokedex_plus_hgss.c`
- Mystery event messages
  - `src/mystery_event_msg.c`, `include/mystery_event_msg.h`

### Map/Region Names
- Region map data (names and entries)
  - `src/data/region_map/region_map_sections.json`
  - `src/data/region_map/region_map_sections_johto.json`
  - `src/data/region_map/region_map_entries_johto.h`, `src/data/region_map/region_map_entries_jk.h`
  - `src/data/region_map/city_map_entries.h`
- UI logic using names
  - `src/map_name_popup.c`, `src/region_map.c`, `src/field_region_map.c`, `src/pokenav_region_map.c`

### Easy Chat Word Banks
- `src/data/easy_chat/*` (multiple groups)
  - `easy_chat_words_by_letter.h`
  - `easy_chat_group_move_1.h`, `easy_chat_group_move_2.h`
  - `easy_chat_group_pokemon.h`, `easy_chat_group_pokemon2.h`
  - Additional groups: greetings, feelings, hobbies, lifestyle, misc, people, speech, status, time, trainer, trendy_saying, voices

### Engine Text Controls: Charmap and Control Codes
- Charmap (glyph-to-byte mapping)
  - `charmap.txt`
- Text engine, placeholders, control codes
  - `gflib/text.h`, `gflib/text.c`, `gflib/string_util.c`
  - Tooling-time mapping: `tools/preproc/charmap.h`
  - Common placeholders: `gStringVar1..4`, `StringExpandPlaceholders`, `EXT_CTRL_CODE_*`

### Other Notable Name Lists
- Trainer class names: `src/data/text/trainer_class_names.h`
- Wonder Trade OT names: `src/data/text/wonder_trade_OT_names.h`
- Contest text tables: `src/data/contest_text_tables.h`
- Party/Pokedex helpers often format names (e.g., `src/party_menu.c`, `src/pokedex_area_screen.c`)

### Graphics-Embedded Text and Fonts
- Fonts/character tiles and rendering
  - `gflib/characters.h` (glyphs), `gflib/text.c` (rendering)
- Graphical UI text assets (labels, keyboards, title elements)
  - `graphics/**` (PNGs, palettes, bins)
  - `src/braille.c` (braille logic and glyphs)

---

## Translation Pipeline Outline

### Source Categories to Export
- Structured arrays in `src/data/text/*.h` (species, moves, items, abilities, natures)
- `src/battle_main.c` type names (`gTypeNames`)
- Master UI strings from `src/strings.c` and scattered `gText_...`
- Script/dialog pools in `data/text/*.inc`, event/script `*.s` and `*.inc`
- Easy Chat groups in `src/data/easy_chat/*`
- Region/map names in `src/data/region_map/*`

### Export/Import Format
- Prefer JSON per category with stable keys:
  - Species/moves/items/abilities/natures/types: numeric IDs as keys
  - UI strings and other `gText_*`: symbolic identifiers as keys
  - Scripts/INC/S files: label or message IDs as keys; preserve control codes
- Import step generates headers/INCs with translated text while preserving control codes and valid characters per `charmap.txt`.

### Tooling
- Add a Python script (e.g., `tools/translate.py`) to:
  - Extract text from the above sources into JSON
  - Validate characters against `charmap.txt`
  - Rebuild headers/INCs from translated JSON before `make`

### Control Codes & Placeholder Safety
- Maintain sequences like `{COLOR ...}`, `{STR_VAR_1}`, `EXT_CTRL_CODE_*` exactly
- Use round-trip tests: export -> import -> diff to ensure no loss

### Graphics Considerations
- Text baked into graphics may need separate pipelines:
  - Replace assets in `graphics/**` with localized variants
  - Ensure fonts support required glyphs; extend `gflib/characters.h` if needed

---

## Quick Pointers by Symbol
- Species: `gSpeciesNames`
- Moves: `gMoveNames`, `gBattleMoves`, `gMoveDescriptionPointers`
- Items: `gItems` (`.name`, `.description`)
- Abilities: `gAbilityNames`, `gAbilityDescriptionPointers`
- Natures: `gNatureNamePointers`
- Types: `gTypeNames`
- UI strings: `gText_*`
- Easy Chat: `src/data/easy_chat/*`
- Map sections: `src/data/region_map/*`
- Charmap: `charmap.txt`




