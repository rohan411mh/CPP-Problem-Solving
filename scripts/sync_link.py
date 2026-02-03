import os
import gspread
from oauth2client.service_account import ServiceAccountCredentials
import time

# 1. Setup Permissions
scope = ["https://spreadsheets.google.com/feeds", "https://www.googleapis.com/auth/drive"]
# Get the absolute path to the directory where THIS script is (the /scripts folder)
script_dir = os.path.dirname(os.path.abspath(__file__))
# Get the root directory (Practise Problem folder)
root_dir = os.path.dirname(script_dir)

creds_path = os.path.join(script_dir, "credentials.json")
creds = ServiceAccountCredentials.from_json_keyfile_name(creds_path, scope)
client = gspread.authorize(creds)

# 2. Open the Sheet
SHEET_NAME = "Problem Solving [Python access]" 
sheet = client.open(SHEET_NAME).sheet1 

def sync_github_links():
    base_repo_url = "https://github.com/rohan411mh/CPP-Problem-Solving/blob/main/"
    ignore_list = ['.git', '.github', '__pycache__', '.vscode', 'scripts']
    
    print("Reading Google Sheet data...")
    all_rows = sheet.get_all_values() 

    print(f"Scanning project root: {root_dir}")

    # We walk starting from root_dir, NOT '..'
    for root, dirs, files in os.walk(root_dir):
        dirs[:] = [d for d in dirs if d not in ignore_list]
        folder_name = os.path.basename(root)
        
        # This prevents it from trying to process files in the root folder itself
        if root == root_dir:
            continue

        for filename in files:
            if filename.endswith(".cpp") and "_" in filename:
                try:
                    raw_serial = filename.split('_')[0]
                    
                    # SAFETY CHECK: Only process if it starts with a number (ignores L10, L11)
                    if not raw_serial.isdigit():
                        continue

                    serial_num = str(int(raw_serial)) 
                    
                    target_row_index = None
                    for i, row in enumerate(all_rows):
                        if len(row) >= 2:
                            if str(row[0]).strip() == folder_name and str(row[1]).strip() == serial_num:
                                target_row_index = i + 1
                                break
                    
                    if target_row_index:
                        full_url = f"{base_repo_url}{folder_name}/{filename}"
                        hyperlink_formula = f'=HYPERLINK("{full_url}", "🔗 View Code")'
                        
                        sheet.update_cell(target_row_index, 8, hyperlink_formula)
                        print(f"✅ Row {target_row_index}: Linked {filename}")
                        time.sleep(1) 
                    else:
                        print(f"⚠️ No match in sheet for: {folder_name} #{serial_num}")

                except Exception as e:
                    print(f"⚠️ Error processing {filename}: {e}")

if __name__ == "__main__":
    sync_github_links()
    print("\n✨ All links updated!")