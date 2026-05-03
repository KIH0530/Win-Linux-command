# Win-Linux-command

A collection of simple C++ implementations of Unix commands for Windows environment.

## Commands

- `ls`: List files in a directory
- `touch`: Create an empty file
- `rm`: Remove a file
- `cat`: Display file contents
- `winfetch`: Display system information with ASCII art (like neofetch)

## Building

Use the provided Makefile:

```bash
make all
```

Or build individual commands:

```bash
make ls
make touch
make rm
make winfetch
make cat
```

## Usage

After building, run the executables:

```bash
./ls.exe [directory]
./touch.exe filename
./rm.exe filename
./cat.exe filename
./winfetch.exe
```

## Requirements

- MinGW-w64 with g++ compiler
- Windows 10 or later for ANSI colors in winfetch

## Language

[中文版](README_CN.md)