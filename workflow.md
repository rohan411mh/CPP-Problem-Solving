## 🛠️ Development Workflow

This document outlines the standard procedure for adding new problems and keeping the repository, tracking sheet, and README in sync.

---

## 📂 Project Structure
```text
Practise Problem/
├── 01_Arrays/           # C++ Source Files
├── 02_Pointers/         # C++ Source Files
├── scripts/             # Automation Engine
│   ├── sync_link.py     # Updates Google Sheets
│   ├── update_readme.py # Updates README.md & Stats
│   └── credentials.json # Google API Keys (Local Only)
├── README.md            # Auto-generated Portfolio
└── update_all.bat       # The "One-Click" Sync Tool

```

---

## 🚀 Daily Routine

### 1. Solve a New Problem

* Create a `.cpp` file in the appropriate topic folder.
* **Naming Convention:** `XX_problem_name.cpp` (e.g., `08_binary_search.cpp`).
* Write and test your code locally.

### 2. Run the Sync Tool

* Double-click `update_all.bat` in the root folder.
* **What happens behind the scenes:**
1. **Sync Sheet:** Python scans your folders and adds clean "View Code" links to your Google Tracking Sheet.
2. **Update README:** Python recalculates total problems and refreshes the tables and "Last Updated" timestamp.
3. **Summary:** The terminal will display how many **new** problems were added and your **total** count.



### 3. Commit to GitHub

* When prompted by the terminal: `💬 Enter your Commit Message:`
* Type a descriptive message (e.g., "Add Binary Search and update stats").
* Hit **Enter**.

---

## ⚠️ Important Notes

* **Never delete the `scripts/` folder.** It contains the logic for the entire automation.
* **Keep `credentials.json` private.** It is listed in `.gitignore` so it won't be uploaded to GitHub.
* **File Naming:** Ensure the filename starts with a number followed by an underscore (`01_name.cpp`) for the scripts to detect it correctly.

---

## 📊 Troubleshooting

* **Link 404 Error:** If a link in the Google Sheet doesn't work, ensure you finished the Git Push step in the terminal.
* **Script Errors:** Ensure you have the required Python libraries installed:
`pip install gspread oauth2client`