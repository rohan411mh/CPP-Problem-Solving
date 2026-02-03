import os

def generate_readme():
    # 1. Initialize the content variable inside the function
    content = "# C++ Problem Solving Log 🚀\n\n"
    content += "This repository tracks my progress in C++. Detailed notes are kept in my Google Sheets tracker.\n\n"
    content += "## 📂 Problem Index\n"
    
    ignore = ['.git', '.vscode', 'update_readme.py']
    
    # 2. Walk through folders
    for root, dirs, files in os.walk('.'):
        dirs[:] = [d for d in dirs if d not in ignore]
        folder_name = os.path.basename(root)
        
        if folder_name and folder_name[0].isdigit():
            content += f"\n### {folder_name.replace('_', ' ')}\n"
            for file in sorted(files):
                if file.endswith('.cpp'):
                    file_path = os.path.join(root, file).replace('\\', '/')
                    clean_name = file.replace('.cpp', '').replace('_', ' ')
                    content += f"- [{clean_name}]({file_path})\n"
    
    # 3. Write the file using UTF-8 encoding to support emojis
    with open("README.md", "w", encoding="utf-8") as f:
        f.write(content)

if __name__ == "__main__":
    generate_readme()
    print("Successfully updated README.md with your latest code!")