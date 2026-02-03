# 🛠️ Development Workflow

This document outlines the standard process for solving problems and keeping the repository/tracker synchronized.

---

## 1. Problem Solving Phase
1.  **Select a Topic:** Go to the relevant folder (e.g., `01_Arrays`).
2.  **Create File:** Use the naming convention `[Number]_[Problem_Name].cpp`.
    * *Example:* `8_Find_Duplicates.cpp`
3.  **Code & Test:** Solve the problem in VS Code.
    * *Note:* `.exe` files are automatically ignored by `.gitignore`.

---

## 2. Documentation Phase (Google Sheets)
1.  **Open Tracker:** Go to the [Problem Solving Tracker] Google Sheet.
2.  **Log Entry:** * Add the **Serial Number** (Column A).
    * Add the **Topic Folder Name** (Column B) — *Must match folder name exactly.*
    * Fill in Problem Statement, Status, and Key Learnings.

---

## 3. Automation Phase (Synchronization)
Run these scripts from the terminal in the root folder to update your records:

### A. Sync Links to Google Sheets
Automatically generates GitHub links and pastes them into Column H of your tracker.
```bash
python sync_link.py