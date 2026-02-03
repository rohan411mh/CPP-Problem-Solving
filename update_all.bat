@echo off
title CPP Portfolio Auto-Sync
cd /d "%~dp0"

echo ------------------------------------------
echo 🤖 STEP 1: Syncing Links to Google Sheets...
echo ------------------------------------------
python sync_link.py

echo.
echo ------------------------------------------
echo 📝 STEP 2: Updating README.md...
echo ------------------------------------------
python update_readme.py

echo.
echo ------------------------------------------
echo 💬 Enter your Commit Message:
echo (e.g., Add problem #8, Fix logic in Arrays, etc.)
echo ------------------------------------------
set /p commit_msg="> "

echo.
echo ------------------------------------------
echo ☁️ STEP 3: Pushing to GitHub...
echo ------------------------------------------
git add .
git commit -m "%commit_msg%"
git push origin main

echo.
echo ✅ SUCCESS: Everything is in sync!
pause