#!/usr/bin/env python3
"""
Fetch French item descriptions from pokeemerald-fr repository
and apply them to the localization CSV file.
"""

import re
import csv
import urllib.request

def fetch_french_item_descriptions():
    """Fetch the French item descriptions from GitHub."""
    url = "https://raw.githubusercontent.com/simsor/pokeemerald-fr/french/src/data/text/item_descriptions.h"
    
    try:
        with urllib.request.urlopen(url) as response:
            content = response.read().decode('utf-8')
        return content
    except Exception as e:
        print(f"Error fetching file: {e}")
        return None

def parse_item_descriptions(content):
    """Parse the item descriptions from the C header file."""
    descriptions = {}
    
    # Match patterns like: static const u8 sMasterBallDesc[] = _(\n    "text");
    # Handle multiline strings
    pattern = r'static const u8 (s\w+Desc)\[\] = _\((.*?)\);'
    
    matches = re.finditer(pattern, content, re.MULTILINE | re.DOTALL)
    
    for match in matches:
        var_name = match.group(1)
        description = match.group(2)
        
        # Extract strings from the description
        # Find all quoted strings
        string_parts = re.findall(r'"([^"]*)"', description)
        full_desc = ''.join(string_parts)
        
        # Replace \n with space for CSV
        full_desc = full_desc.replace('\\n', ' ')
        # Clean up multiple spaces
        full_desc = re.sub(r'\s+', ' ', full_desc).strip()
        
        descriptions[var_name] = full_desc
    
    return descriptions

def read_items_h_mapping(items_h_path):
    """Read the mapping from items.h between ITEM_NAME and description variable."""
    with open(items_h_path, 'r', encoding='utf-8') as f:
        content = f.read()
    
    mapping = {}
    
    # Find patterns like: [ITEM_MASTER_BALL] = { ... .description = sMasterBallDesc, ...
    pattern = r'\[([A-Z_0-9]+)\]\s*=\s*\{[^}]*\.description\s*=\s*(s\w+Desc)'
    
    matches = re.finditer(pattern, content, re.MULTILINE | re.DOTALL)
    
    for match in matches:
        item_id = match.group(1)
        desc_var = match.group(2)
        mapping[item_id] = desc_var
    
    return mapping

def update_csv_file(csv_path, french_descs, item_mapping):
    """Update the CSV file with French translations."""
    # Read existing CSV
    rows = []
    updates = 0
    
    with open(csv_path, 'r', encoding='utf-8') as f:
        reader = csv.DictReader(f)
        for row in reader:
            item_id = row['id']
            
            # Skip empty items
            if not item_id or item_id == 'ITEM_NONE':
                rows.append(row)
                continue
            
            # Get the description variable name from the mapping
            if item_id in item_mapping:
                desc_var = item_mapping[item_id]
                
                # Get the French description
                if desc_var in french_descs:
                    row['description'] = french_descs[desc_var]
                    updates += 1
            
            rows.append(row)
    
    # Write updated CSV
    with open(csv_path, 'w', encoding='utf-8', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=['id', 'description'])
        writer.writeheader()
        writer.writerows(rows)
    
    print(f"Updated {updates} items in {csv_path}")
    return updates

if __name__ == "__main__":
    print("Fetching French item descriptions...")
    content = fetch_french_item_descriptions()
    
    if content:
        print("Parsing descriptions...")
        french_descs = parse_item_descriptions(content)
        print(f"Found {len(french_descs)} French descriptions")
        
        print("Reading item mapping from items.h...")
        item_mapping = read_items_h_mapping("src/data/items.h")
        print(f"Found {len(item_mapping)} item mappings")
        
        csv_path = "localization/fr/templates/item_descriptions.csv"
        print(f"Updating {csv_path}...")
        updates = update_csv_file(csv_path, french_descs, item_mapping)
        
        if updates > 0:
            print("Done!")
        else:
            print("Warning: No items were updated. Check the mappings.")
    else:
        print("Failed to fetch file from GitHub")
