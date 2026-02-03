@echo off
echo 🔄 Syncing Links to Google Sheets...
python sync_link.py

echo 📝 Updating README.md...
python update_readme.py

echo ☁️ Pushing changes to GitHub...
git add .
git commit -m "Automated update: Sync Sheet and README"
git push origin main

echo ✅ All Done! Everything is in sync.
pause