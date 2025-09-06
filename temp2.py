import os
import codecs

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
        encoding = result['encoding']
        # 确保返回一个有效的编码
        if encoding:
            return encoding
    except (ImportError, KeyError):
        pass
    
    # 默认返回utf-8
    return 'utf-8'

def convert_to_utf8(file_path):
    """
    将文件转换为UTF-8编码
    """
    encoding = detect_encoding(file_path)
    print(f"文件 {file_path} 的编码是: {encoding}")
    
    if encoding.lower() == 'utf-8':
        print("文件已经是UTF-8编码，无需转换")
        return False
    
    try:
        # 使用二进制模式读取文件，避免编码问题
        with open(file_path, 'rb') as f:
            raw_data = f.read()
        
        # 尝试多种方式解码
        content = None
        # 首先尝试检测到的编码
        try:
            content = raw_data.decode(encoding)
        except (UnicodeDecodeError, LookupError):
            # 如果失败，尝试其他常见编码
            fallback_encodings = ['utf-8', 'gbk', 'gb2312', 'ascii', 'latin1', 'ISO-8859-1']
            for enc in fallback_encodings:
                try:
                    content = raw_data.decode(enc)
                    print(f"使用备用编码 {enc} 成功解码文件")
                    break
                except (UnicodeDecodeError, LookupError):
                    continue
        
        # 如果所有编码都失败了
        if content is None:
            print(f"无法使用任何已知编码解码文件 {file_path}")
            return False
        
        # 创建备份文件
        backup_path = file_path + ".bak"
        with open(backup_path, 'wb') as backup:
            backup.write(raw_data)
        
        # 写入UTF-8编码的文件
        with codecs.open(file_path, 'w', encoding='utf-8') as f:
            f.write(content)
            
        print(f"成功转换为UTF-8编码，原文件已备份为 {backup_path}")
        return True
    except Exception as e:
        print(f"处理文件失败 {file_path}: {e}")
        return False

if __name__ == "__main__":
    # 定义文件路径
    file_paths = [
        r"D:\VSCODE_PROJ\Data-Structure\DSA_for_vscode\_input\prime-4096-bitmap.txt",
        r"D:\VSCODE_PROJ\Data-Structure\DSA_for_vscode\_input\prime-1048576-bitmap.txt"
    ]
    
    # 处理每个文件
    for file_path in file_paths:
        if os.path.exists(file_path):
            print(f"处理文件: {file_path}")
            convert_to_utf8(file_path)
        else:
            print(f"文件不存在: {file_path}")