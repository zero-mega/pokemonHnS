#!/usr/bin/env python3
"""
Fetch French move descriptions from pokeemerald-fr repository
and apply them to the localization CSV file.
"""

import re
import csv
import urllib.request

def fetch_french_move_descriptions():
    """Fetch the French move descriptions from GitHub."""
    url = "https://raw.githubusercontent.com/simsor/pokeemerald-fr/french/src/data/text/move_descriptions.h"
    
    try:
        with urllib.request.urlopen(url) as response:
            content = response.read().decode('utf-8')
        return content
    except Exception as e:
        print(f"Error fetching file: {e}")
        return None

def parse_move_descriptions(content):
    """Parse the move descriptions from the C header file."""
    descriptions = {}
    
    # Match patterns like: static const u8 sPoundDescription[] = _(\n    "text");
    # Handle multiline strings
    pattern = r'static const u8 (s\w+Description)\[\] = _\((.*?)\);'
    
    matches = re.finditer(pattern, content, re.MULTILINE | re.DOTALL)
    
    for match in matches:
        var_name = match.group(1)
        description = match.group(2)
        
        # Extract strings from the description
        # Find all quoted strings
        string_parts = re.findall(r'"([^"]*)"', description)
        full_desc = ''.join(string_parts)
        
        # Keep \n in the description as they are part of the format
        # Clean up multiple spaces but keep newlines
        full_desc = re.sub(r' +', ' ', full_desc).strip()
        
        descriptions[var_name] = full_desc
    
    return descriptions

def read_move_data_mapping():
    """Read the mapping from the English move descriptions file."""
    try:
        with open('src/data/text/move_descriptions.h', 'r', encoding='utf-8') as f:
            content = f.read()
    except Exception as e:
        print(f"Error reading local move descriptions: {e}")
        return {}
    
    mapping = {}
    
    # Find the gMoveDescriptionPointers array
    # Match patterns like: [MOVE_POUND - 1] = sPoundDescription,
    pattern = r'\[([A-Z_0-9]+)\s*(?:-\s*1)?\]\s*=\s*(s\w+Description)'
    
    matches = re.finditer(pattern, content, re.MULTILINE)
    
    for match in matches:
        move_id = match.group(1)
        desc_var = match.group(2)
        mapping[move_id] = desc_var
    
    return mapping

def update_csv_file(csv_path, french_descs, move_mapping):
    """Update the CSV file with French translations."""
    # Read existing CSV
    rows = []
    updates = 0
    
    with open(csv_path, 'r', encoding='utf-8') as f:
        reader = csv.DictReader(f)
        for row in reader:
            move_id = row['id']
            
            # Skip empty moves
            if not move_id:
                rows.append(row)
                continue
            
            # Get the description variable name from the mapping
            if move_id in move_mapping:
                desc_var = move_mapping[move_id]
                
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
    
    print(f"Updated {updates} moves in {csv_path}")
    return updates

if __name__ == "__main__":
    print("Fetching French move descriptions...")
    content = fetch_french_move_descriptions()
    
    if content:
        print("Parsing descriptions...")
        french_descs = parse_move_descriptions(content)
        print(f"Found {len(french_descs)} French descriptions")
        
        print("Reading move mapping from local file...")
        move_mapping = read_move_data_mapping()
        print(f"Found {len(move_mapping)} move mappings")
        
        csv_path = "localization/fr/templates/move_descriptions.csv"
        print(f"Updating {csv_path}...")
        updates = update_csv_file(csv_path, french_descs, move_mapping)
        
        if updates > 0:
            print("Done!")
        else:
            print("Warning: No moves were updated. Check the mappings.")
    else:
        print("Failed to fetch file from GitHub")

