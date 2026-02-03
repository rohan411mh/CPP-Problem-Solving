import os
import gspread
from oauth2client.service_account import ServiceAccountCredentials
import time

# 1. Setup Permissions
scope = ["https://spreadsheets.google.com/feeds", "https://www.googleapis.com/auth/drive"]
creds = ServiceAccountCredentials.from_json_keyfile_name("credentials.json", scope)
client = gspread.authorize(creds)

# 2. Open the Sheet (Make sure this matches exactly what the debug script found)
SHEET_NAME = "Problem Solving [Python access]" 
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
                    serial_num = filename.split('_')[0]
                    
                    target_row_index = None
                    for i, row in enumerate(all_rows):
                        if len(row) >= 2:
                            # Matches Column A (Topic) and Column B (#)
                            if str(row[0]).strip() == folder_name and str(row[1]).strip() == str(serial_num):
                                target_row_index = i + 1
                                break
                    
                    if target_row_index:
                        full_url = f"{base_repo_url}{folder_name}/{filename}"
                        
                        # NEW LOGIC: Use HYPERLINK formula for a cleaner look
                        hyperlink_formula = f'=HYPERLINK("{full_url}", "🔗 View Code")'
                        
                        # Update Column H (8th column) with the formula
                        sheet.update_cell(target_row_index, 8, hyperlink_formula)
                        print(f"✅ Row {target_row_index}: Linked {filename} with clean label")
                        
                        time.sleep(1) 
                    else:
                        print(f"⚠️ No match for: {folder_name} #{serial_num}")

                except Exception as e:
                    print(f"⚠️ Error processing {filename}: {e}")

if __name__ == "__main__":
    sync_github_links()
    print("\n✨ All links updated to clean 'View Code' format!")