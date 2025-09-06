import os
import re
import codecs
from pathlib import Path

def detect_encoding(file_path):
    """
    检测文件编码
    """
    with open(file_path, 'rb') as f:
        raw_data = f.read()
        
    # 常见编码列表
    encodings = ['utf-8', 'gbk', 'gb2312', 'ascii']
    
    for encoding in encodings:
        try:
            raw_data.decode(encoding)
            return encoding
        except UnicodeDecodeError:
            continue
    
    # 如果常见编码都不行，使用chardet库（如果安装了的话）
    try:
        import chardet
        result = chardet.detect(raw_data)
        return result['encoding']
    except ImportError:
        # 默认返回utf-8
        return 'utf-8'

def convert_pragma_once_to_include_guard(file_path):
    """
    将#pragma once替换为包含保护
    """
    # 检测文件编码
    encoding = detect_encoding(file_path)
    
    # 读取文件内容
    try:
        with codecs.open(file_path, 'r', encoding=encoding) as f:
            lines = f.readlines()
    except UnicodeDecodeError:
        print(f"无法读取文件 {file_path}，编码可能不正确")
        return False
    
    # 检查是否包含#pragma once
    pragma_once_line_index = None
    for i, line in enumerate(lines):
        if line.strip() == '#pragma once':
            pragma_once_line_index = i
            break
    
    # 如果没有找到#pragma once，则不需要处理
    if pragma_once_line_index is None:
        return False
    
    # 生成包含保护的宏名
    filename = os.path.basename(file_path)
    macro_name = filename.upper().replace('.', '_').replace('-', '_')
    
    # 构造新的包含保护行
    include_guard_lines = [
        f'#ifndef {macro_name}\n',
        f'#define {macro_name}\n'
    ]
    
    # 删除#pragma once行及其以上的内容，保留剩余部分
    remaining_lines = lines[pragma_once_line_index+1:]
    
    # 组合新的内容：包含保护 + 原有内容（#pragma once之后的部分）+ #endif
    new_lines = include_guard_lines + remaining_lines + ['\n#endif\n']
    
    # 写入UTF-8编码的文件
    with codecs.open(file_path, 'w', encoding='utf-8') as f:
        f.writelines(new_lines)
    
    return True

def convert_to_utf8(file_path):
    """
    将文件转换为UTF-8编码
    """
    encoding = detect_encoding(file_path)
    if encoding.lower() == 'utf-8':
        return False
    
    try:
        with codecs.open(file_path, 'r', encoding=encoding) as f:
            content = f.read()
        
        with codecs.open(file_path, 'w', encoding='utf-8') as f:
            f.write(content)
            
        return True
    except Exception as e:
        print(f"  处理文件失败 {file_path}: {e}")
        return False

def process_files(directory):
    """
    处理目录中的所有.h和.cpp文件
    """
    # 获取所有.h和.cpp文件
    h_files = list(Path(directory).rglob("*.h"))
    cpp_files = list(Path(directory).rglob("*.cpp"))
    
    processed_count = 0
    
    # 处理.h文件
    for file_path in h_files:
        print(f"处理文件: {file_path}")
        if convert_pragma_once_to_include_guard(file_path):
            print(f"  成功替换#pragma once为包含保护: {file_path}")
            processed_count += 1
        else:
            print(f"  文件无需更改或处理失败: {file_path}")
    
    # 处理所有.h和.cpp文件，转换为UTF-8编码
    all_files = h_files + cpp_files
    for file_path in all_files:
        if convert_to_utf8(file_path):
            print(f"  成功转换为UTF-8编码: {file_path}")
            processed_count += 1
    
    print(f"\n总共处理了 {processed_count} 个文件")

if __name__ == "__main__":
    # 获取当前工作目录
    # current_dir = os.getcwd()
    # print(f"当前工作目录: {current_dir}")
    filelist = ['gs']  
    current_dir = "D:\\VSCODE_PROJ\\Data-Structure\\DSA_for_vscode\\src\\"
    # 循环将obj_dir=current_dir连接filelist[i]
    for i in range(len(filelist)):
        obj_dir = os.path.join(current_dir, filelist[i])
        process_files(obj_dir)
    
    # 处理文件
    # process_files(current_dir)