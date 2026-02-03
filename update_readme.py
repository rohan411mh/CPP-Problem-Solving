import os

def generate_readme():
    # 1. Configuration
    header = "# 🚀 C++ Problem Solving Journey\n\n"
    ignore_list = ['.git', '.github', '__pycache__', '.vscode']
    
    # 2. Get all topic directories
    topics = sorted([d for d in os.listdir('.') if os.path.isdir(d) and d not in ignore_list])
    
    # 3. Count total problems and build content
    total_problems = 0
    content = ""
    
    for topic in topics:
        content += f"## 📁 {topic.replace('_', ' ')}\n"
        content += "| # | Problem Name | Code Link |\n"
        content += "|---|--------------|-----------|\n"
        
        folder_path = os.path.join('.', topic)
        files = sorted([f for f in os.listdir(folder_path) if f.endswith('.cpp')])
        
        for file in files:
            total_problems += 1  # Increment the counter
            if "_" in file:
                parts = file.replace(".cpp", "").split("_", 1)
                num = parts[0]
                name = parts[1].replace("_", " ")
                link = f"https://github.com/rohan411mh/CPP-Problem-Solving/blob/main/{topic}/{file}"
                content += f"| {num} | {name} | [View Solution]({link}) |\n"
        
        content += "\n"

    # 4. Create the Stats Section (Badges look great here!)
    stats = f"### 📊 Stats\n"
    stats += f"**Total Problems Solved:** {total_problems}\n\n"
    stats += "---\n\n"
    
    intro = "This repository tracks my progress as I master C++. Every solution is linked to my tracking sheet and categorized by topic.\n\n"

    # 5. Write to README.md (Header + Stats + Intro + Table)
    with open("README.md", "w", encoding="utf-8") as f:
        f.write(header + stats + intro + content)
    
    print(f"✨ README.md updated! Total problems found: {total_problems}")

if __name__ == "__main__":
    generate_readme()