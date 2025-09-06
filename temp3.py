import json
import os
import re

def fix_json_content(content):
    """
    修复常见的JSON格式问题
    """
    # 移除注释行 (以//开头的行)
    lines = content.split('\n')
    cleaned_lines = []
    for line in lines:
        # 移除行内注释
        if '//' in line:
            # 检查//是否在字符串内
            in_string = False
            for i, char in enumerate(line):
                if char == '"' and (i == 0 or line[i-1] != '\\'):
                    in_string = not in_string
                elif char == '/' and i+1 < len(line) and line[i+1] == '/' and not in_string:
                    line = line[:i]
                    break
        cleaned_lines.append(line)
    
    content = '\n'.join(cleaned_lines)
    
    # 移除末尾多余的逗号
    content = re.sub(r',(\s*[}\]])', r'\1', content)
    
    return content

def add_task_and_launch_config(tasks_file, launch_file, project_name):
    """
    在tasks.json和launch.json中添加新的项目配置
    
    Args:
        tasks_file: tasks.json文件路径
        launch_file: launch.json文件路径
        project_name: 项目名称
    """
    
    # 构建新的task配置
    new_task = {
        "type": "cppbuild",
        "label": f"build {project_name} Debug",
        "command": "D:\\ProgramData\\mingw64_14\\mingw64\\bin\\g++.exe",
        "args": [
            "-fdiagnostics-color=always",
            "-g",
            "-std=c++23",
            "-fpermissive",
            "-I${workspaceFolder}/src/gs",
            "-o",
            f"${{workspaceFolder}}\\bulid\\Debug.{project_name}\\{project_name}.exe",
            f"./{project_name}/*.cpp",
            # "./huffman/Huffman_PQ_Test.cpp",
            # "./huffman/Huffman_PQ_generateTree.cpp",
            # "./huffman/huffman_PQ_initForest.cpp",
            # "./huffman/huffman_statistics.cpp",
            # "./huffman/huffman_generateTable.cpp",
            # "./huffman/huffman_decode.cpp",
            # "./huffman/huffman_encode.cpp",
            # "./prime/primeNLT.cpp",
            # "./UniPrint/print_basic.cpp",
            # "./UniPrint/print_HuffChar.cpp"
        ],
        "options": {
            "cwd": "${workspaceFolder}/src"
        },
        "problemMatcher": ["$gcc"],
        "group": {
            "kind": "build",
            "isDefault": True
        },
        "detail": "编译器: D:\\ProgramData\\mingw64_14\\mingw64\\bin\\g++.exe"
    }
    
    # 构建新的launch配置
    new_launch = {
        "name": f"{project_name} Debug",
        "type": "cppdbg",
        "request": "launch",
        "program": f"${{workspaceFolder}}/bulid/Debug.{project_name}/{project_name}.exe",
        "args": [

            ],
        "stopAtEntry": False,
        "cwd": "${fileDirname}",
        "environment": [],
        "externalConsole": True,
        "MIMode": "gdb",
        "miDebuggerPath": "D:\\ProgramData\\mingw64_14\\mingw64\\bin\\gdb.exe",
        "setupCommands": [
            {
                "description": "为 gdb 启用整齐打印",
                "text": "-enable-pretty-printing",
                "ignoreFailures": True
            }
        ],
        "preLaunchTask": f"build {project_name} Debug",
        "internalConsoleOptions": "neverOpen"
    }
    
    # 读取并更新tasks.json
    if os.path.exists(tasks_file):
        try:
            with open(tasks_file, 'r', encoding='utf-8') as f:
                content = f.read()
            
            # 修复JSON格式
            content = fix_json_content(content)
            
            # 解析JSON
            tasks_data = json.loads(content)
            
            # 检查是否已存在同名任务
            task_exists = False
            for task in tasks_data.get("tasks", []):
                if task.get("label") == f"build {project_name} Debug":
                    task_exists = True
                    break
            
            # 如果不存在，则添加新任务
            if not task_exists:
                tasks_data["tasks"].append(new_task)
                
                # 写回文件
                with open(tasks_file, 'w', encoding='utf-8') as f:
                    json.dump(tasks_data, f, ensure_ascii=False, indent=4)
                
                print(f"已在 {tasks_file} 中添加 {project_name} 的构建任务")
            else:
                print(f"任务 'build {project_name} Debug' 已存在，无需添加")
        except json.JSONDecodeError as e:
            print(f"解析 {tasks_file} 失败: {e}")
            print("请检查JSON文件格式是否正确")
        except Exception as e:
            print(f"处理 {tasks_file} 时发生错误: {e}")
    else:
        print(f"文件 {tasks_file} 不存在")
    
    # 读取并更新launch.json
    if os.path.exists(launch_file):
        try:
            with open(launch_file, 'r', encoding='utf-8') as f:
                content = f.read()
            
            # 修复JSON格式
            content = fix_json_content(content)
            
            # 解析JSON
            launch_data = json.loads(content)
            
            # 检查是否已存在同名配置
            launch_exists = False
            for config in launch_data.get("configurations", []):
                if config.get("name") == f"{project_name} Debug":
                    launch_exists = True
                    break
            
            # 如果不存在，则添加新配置
            if not launch_exists:
                launch_data["configurations"].append(new_launch)
                
                # 写回文件
                with open(launch_file, 'w', encoding='utf-8') as f:
                    json.dump(launch_data, f, ensure_ascii=False, indent=4)
                
                print(f"已在 {launch_file} 中添加 {project_name} 的调试配置")
            else:
                print(f"调试配置 '{project_name} Debug' 已存在，无需添加")
        except json.JSONDecodeError as e:
            print(f"解析 {launch_file} 失败: {e}")
            print("请检查JSON文件格式是否正确")
        except Exception as e:
            print(f"处理 {launch_file} 时发生错误: {e}")
    else:
        print(f"文件 {launch_file} 不存在")

if __name__ == "__main__":
    # 用户输入项目名称
    # project_name = input("请输入项目名称(xxx): ")
    # if not project_name:
    # project_name = "SMMH"
    filelist = ['gs']  
    tasks_file = r"D:\VSCODE_PROJ\Data-Structure\DSA_for_vscode\.vscode\tasks.json"
    launch_file = r"D:\VSCODE_PROJ\Data-Structure\DSA_for_vscode\.vscode\launch.json"
    for i in range(len(filelist)):
        project_name = filelist[i]
        # 添加配置
        add_task_and_launch_config(tasks_file, launch_file, project_name)