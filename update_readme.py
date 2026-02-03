import os

def generate_readme():
    header = "# 🚀 C++ Problem Solving Journey\n\n"
    intro = "This repository tracks my progress as I master C++. Every solution is linked to my tracking sheet and categorized by topic.\n\n"
    
    # Folders to ignore
    ignore_list = ['.git', '.github', '__pycache__', '.vscode']
    
    # Get all directories and sort them (01_Arrays, 02_Pointers, etc.)
    topics = sorted([d for d in os.listdir('.') if os.path.isdir(d) and d not in ignore_list])
    
    content = ""
    for topic in topics:
        content += f"## 📁 {topic.replace('_', ' ')}\n"
        content += "| # | Problem Name | Code Link |\n"
        content += "|---|--------------|-----------|\n"
        
        # Get all .cpp files in this topic folder
        folder_path = os.path.join('.', topic)
        files = sorted([f for f in os.listdir(folder_path) if f.endswith('.cpp')])
        
        for file in files:
            if "_" in file:
                # Split '1_Name.cpp' into '1' and 'Name'
                parts = file.replace(".cpp", "").split("_", 1)
                num = parts[0]
                name = parts[1].replace("_", " ")
                
                # Create the GitHub link
                link = f"https://github.com/rohan411mh/CPP-Problem-Solving/blob/main/{topic}/{file}"
                
                content += f"| {num} | {name} | [View Solution]({link}) |\n"
        
        content += "\n"

    # Write to README.md
    with open("README.md", "w", encoding="utf-8") as f:
        f.write(header + intro + content)
    
    print("✨ README.md updated successfully with all topics!")

if __name__ == "__main__":
    generate_readme()