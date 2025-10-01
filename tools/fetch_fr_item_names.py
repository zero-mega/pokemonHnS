#!/usr/bin/env python3
"""
Fetch French item names from pokeemerald-fr repository
and apply them to the localization CSV file.
"""

import re
import csv
import urllib.request

def fetch_french_items():
    """Fetch the French items from GitHub."""
    url = "https://raw.githubusercontent.com/simsor/pokeemerald-fr/french/src/data/items.h"
    
    try:
        with urllib.request.urlopen(url) as response:
            content = response.read().decode('utf-8')
        return content
    except Exception as e:
        print(f"Error fetching file: {e}")
        return None

def parse_item_names(content):
    """Parse the item names from the C header file."""
    item_names = {}
    
    # Match patterns like:
    # [ITEM_MASTER_BALL] = {
    #     .name = _("MASTER BALL"),
    # Looking for the item ID and then the name field
    
    # Split into item blocks
    pattern = r'\[([A-Z_0-9]+)\]\s*=\s*\{([^}]+)\}'
    
    matches = re.finditer(pattern, content, re.MULTILINE | re.DOTALL)
    
    for match in matches:
        item_id = match.group(1)
        item_block = match.group(2)
        
        # Extract the name from the block
        name_pattern = r'\.name\s*=\s*_\("([^"]+)"\)'
        name_match = re.search(name_pattern, item_block)
        
        if name_match:
            item_name = name_match.group(1)
            item_names[item_id] = item_name
    
    return item_names

def update_csv_file(csv_path, french_names):
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
            
            # Get the French name
            if item_id in french_names:
                row['name'] = french_names[item_id]
                updates += 1
            
            rows.append(row)
    
    # Write updated CSV
    with open(csv_path, 'w', encoding='utf-8', newline='') as f:
        writer = csv.DictWriter(f, fieldnames=['id', 'name'])
        writer.writeheader()
        writer.writerows(rows)
    
    print(f"Updated {updates} items in {csv_path}")
    return updates

if __name__ == "__main__":
    print("Fetching French item names...")
    content = fetch_french_items()
    
    if content:
        print("Parsing item names...")
        french_names = parse_item_names(content)
        print(f"Found {len(french_names)} French item names")
        
        csv_path = "localization/fr/templates/items.csv"
        print(f"Updating {csv_path}...")
        updates = update_csv_file(csv_path, french_names)
        
        if updates > 0:
            print("Done!")
        else:
            print("Warning: No items were updated. Check the mappings.")
    else:
        print("Failed to fetch file from GitHub")

