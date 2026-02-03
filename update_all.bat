@echo off
setlocal enabledelayedexpansion
title CPP Portfolio Auto-Sync
cd /d "%~dp0"

echo ------------------------------------------
echo 🤖 STEP 1: Syncing Links to Google Sheets...
echo ------------------------------------------
python scripts\sync_link.py

echo.
echo ------------------------------------------
echo 📝 STEP 2: Updating README.md...
echo ------------------------------------------
:: Run python and capture the TOTAL_COUNT line
for /f "tokens=2 delims=:" %%A in ('python scripts\update_readme.py ^| findstr "TOTAL_COUNT"') do set total=%%A

:: Count how many .cpp files are "New" (staged but not committed)
set new_count=0
for /f %%i in ('git status --short ^| findstr /C:".cpp" ^| find /c /v ""') do set new_count=%%i

echo.
echo ==========================================
echo ✅ UPDATE SUMMARY:
echo 🆕 New Problems Added: %new_count%
echo 📚 Total Problems Now: %total%
echo ==========================================

echo.
echo 💬 Enter your Commit Message:
set /p commit_msg="> "

echo.
echo ------------------------------------------
echo ☁️ STEP 3: Pushing to GitHub...
echo ------------------------------------------
git add .
git commit -m "%commit_msg%"
git push origin main

echo.
echo ✅ ALL DONE: Everything is in sync!
pause