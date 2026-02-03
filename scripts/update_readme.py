import os
from datetime import datetime

def generate_readme():
    header = "# 🚀 C++ Problem Solving Journey\n\n"
    ignore_list = ['.git', '.github', '__pycache__', '.vscode', 'scripts']
    
    # Define absolute root path
    script_dir = os.path.dirname(os.path.abspath(__file__))
    root_dir = os.path.dirname(script_dir)
    
    # Get topics only from inside Practise Problem folder
    # Added .isdigit() check to topic folders for extra safety
    topics = sorted([d for d in os.listdir(root_dir) 
                    if os.path.isdir(os.path.join(root_dir, d)) 
                    and d not in ignore_list 
                    and d[0].isdigit()])
    
    total_problems = 0
    last_updated = datetime.now().strftime("%Y-%m-%d %H:%M:%S")

    philosophy = """
> [!IMPORTANT]
> **Logic & Code:** 100% handwritten by me.  
> **Automation:** Python scripts (sync & readme) built with the help of AI to maintain an efficient workflow.

This repository tracks my progress as I master C++. Every solution is linked to my tracking sheet and categorized by topic.\n\n"""

    table_content = ""
    
    for topic in topics:
        table_content += f"## 📁 {topic.replace('_', ' ')}\n"
        table_content += "| # | Problem Name | Code Link |\n"
        table_content += "|---|--------------|-----------|\n"
        
        folder_path = os.path.join(root_dir, topic)
        files = sorted([f for f in os.listdir(folder_path) if f.endswith('.cpp')])
        
        for file in files:
            total_problems += 1  
            if "_" in file:
                parts = file.replace(".cpp", "").split("_", 1)
                num = parts[0]
                name = parts[1].replace("_", " ")
                link = f"https://github.com/rohan411mh/CPP-Problem-Solving/blob/main/{topic}/{file}"
                table_content += f"| {num} | {name} | [View Solution]({link}) |\n"
        
        table_content += "\n"

    stats = f"### 📊 Stats\n"
    stats += f"**Total Problems Solved:** {total_problems}  \n"
    stats += f"**Last Updated:** {last_updated}\n\n"
    stats += "-----"

    # Save README to root_dir
    readme_path = os.path.join(root_dir, "README.md")
    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(header + stats + philosophy + table_content)
    
    return total_problems

if __name__ == "__main__":
    count = generate_readme()
    print(f"TOTAL_COUNT:{count}")