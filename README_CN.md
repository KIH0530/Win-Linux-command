# CppStudy

在 Windows 环境下实现的简单 Unix 命令的 C++ 集合。

## 命令

- `ls`: 列出目录中的文件
- `touch`: 创建空文件
- `rm`: 删除文件
- `cat`: 显示文件内容
- `winfetch`: 显示系统信息和 ASCII 艺术（类似 neofetch）

## 构建

使用提供的 Makefile：

```bash
make all
```

或单独构建命令：

```bash
make ls
make touch
make rm
make cat
make winfetch
```

## 使用

构建后，运行可执行文件：

```bash
./ls.exe [目录]
./touch.exe 文件名
./rm.exe 文件名
./cat.exe 文件名
./winfetch.exe
```

## 要求

- 带有 g++ 编译器的 MinGW-w64
- Windows 10 或更高版本以支持 winfetch 中的 ANSI 颜色

## 语言

[English](README.md)