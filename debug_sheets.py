import gspread
from oauth2client.service_account import ServiceAccountCredentials

# Setup
scope = ["https://spreadsheets.google.com/feeds", "https://www.googleapis.com/auth/drive"]
creds = ServiceAccountCredentials.from_json_keyfile_name("credentials.json", scope)
client = gspread.authorize(creds)

print("🤖 Bot is looking for spreadsheets...")
spreadsheets = client.list_spreadsheet_files()

if not spreadsheets:
    print("❌ The bot cannot see ANY spreadsheets.")
    print("Please open credentials.json, copy the 'client_email', and share your sheet with it.")
else:
    print("✅ The bot found these spreadsheets:")
    for sheet in spreadsheets:
        print(f" - '{sheet['name']}'")