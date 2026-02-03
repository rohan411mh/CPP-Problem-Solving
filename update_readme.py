import os

def generate_readme():
    # 1. Configuration
    header = "# 🚀 C++ Problem Solving Journey\n\n"
    ignore_list = ['.git', '.github', '__pycache__', '.vscode']
    
    # 2. Get all topic directories
    topics = sorted([d for d in os.listdir('.') if os.path.isdir(d) and d not in ignore_list])
    
    # 3. Stats and Intro Content
    total_problems = 0
    
    # This is the "Philosophy" section we discussed
    philosophy = """
> [!IMPORTANT]
> **Logic & Code:** 100% handwritten by me.  
> **Automation:** Python scripts (sync & readme) built with the help of AI to maintain an efficient workflow.

This repository tracks my progress as I master C++. Every solution is linked to my tracking sheet and categorized by topic.\n\n"""

    table_content = ""
    
    # 4. Generate the Tables
    for topic in topics:
        table_content += f"## 📁 {topic.replace('_', ' ')}\n"
        table_content += "| # | Problem Name | Code Link |\n"
        table_content += "|---|--------------|-----------|\n"
        
        folder_path = os.path.join('.', topic)
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

    # 5. Create the Stats Section
    stats = f"### 📊 Stats\n"
    stats += f"**Total Problems Solved:** {total_problems}\n\n"
    stats += "---\n\n"

    # 6. Write to README.md (Order: Header -> Stats -> Philosophy -> Table)
    with open("README.md", "w", encoding="utf-8") as f:
        f.write(header + stats + philosophy + table_content)
    
    print(f"✨ README.md updated! Total problems found: {total_problems}")

if __name__ == "__main__":
    generate_readme()