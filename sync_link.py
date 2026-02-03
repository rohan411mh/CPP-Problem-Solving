import os
import gspread
from oauth2client.service_account import ServiceAccountCredentials
import time

# 1. Setup Permissions
scope = ["https://spreadsheets.google.com/feeds", "https://www.googleapis.com/auth/drive"]
creds = ServiceAccountCredentials.from_json_keyfile_name("credentials.json", scope)
client = gspread.authorize(creds)

# 2. Open the Sheet (MATCH YOUR SHEET NAME EXACTLY)
SHEET_NAME = "CPP Problem Solving" 
sheet = client.open(SHEET_NAME).sheet1 

def sync_github_links():
    base_repo_url = "https://github.com/rohan411mh/CPP-Problem-Solving/blob/main/"
    ignore_list = ['.git', '.github', '__pycache__', '.vscode']
    
    print("Reading Google Sheet data...")
    all_rows = sheet.get_all_values() 

    print("Scanning folders for .cpp files...")

    for root, dirs, files in os.walk("."):
        dirs[:] = [d for d in dirs if d not in ignore_list]
        folder_name = os.path.basename(root)
        
        if not folder_name or folder_name in [".", "Practise Problem"]:
            continue

        for filename in files:
            if filename.endswith(".cpp") and "_" in filename:
                try:
                    # Extract Serial Number
                    serial_num = filename.split('_')[0]
                    
                    # Search for matching Row
                    target_row_index = None
                    for i, row in enumerate(all_rows):
                        if len(row) >= 2:
                            if str(row[0]).strip() == str(serial_num) and str(row[1]).strip() == folder_name:
                                target_row_index = i + 1
                                break
                    
                    if target_row_index:
                        full_link = f"{base_repo_url}{folder_name}/{filename}"
                        sheet.update_cell(target_row_index, 8, full_link)
                        print(f"✅ Row {target_row_index}: Synced {folder_name} #{serial_num}")
                        time.sleep(1) 
                    else:
                        print(f"⚠️ No match in sheet for: {folder_name} file #{serial_num}")

                except Exception as e:
                    print(f"⚠️ Error processing {filename}: {e}")

if __name__ == "__main__":
    sync_github_links()
    print("\nDone!")