#!/bin/bash

ccrun() {
    # 检查参数数量
    if [[ $# -gt 3 ]]; then
        echo "Error: too many arguments" >&2
        return 1
    fi

    # 检查源文件是否存在
    if [[ ! -f "$1.cpp" ]]; then
        echo "Error: $1.cpp not found" >&2
        return 1
    fi

    # 编译C++程序
    g++-13 "$1.cpp" -o "$1" -g -O2 -std=c++20 \
        -Wall -fsanitize=undefined -fsanitize=address

    # 检查编译是否成功
    if [[ $? -ne 0 ]]; then
        echo "Error: compilation failed" >&2
        return 1
    fi

    echo "compile successfully" >&2

    # 根据参数数量执行不同的操作
    if [[ $# -eq 1 ]]; then
        # 无输入输出文件，直接运行
        "./$1"
    elif [[ $# -eq 2 ]]; then
        # 有输入文件，检查文件类型
        if [[ "$2" != *.txt && "$2" != *.in ]]; then
            echo "Error: input file type error, $2 is neither txt, nor in" >&2
            return 1
        fi
        # 从输入文件重定向运行
        "./$1" < "$2"
    else
        # 有输入和输出文件，检查文件类型
        if [[ "$2" != *.txt && "$2" != *.in ]]; then
            echo "Error: input file type error, $2 is neither txt, nor in" >&2
            return 1
        fi
        if [[ "$3" != *.txt && "$3" != *.out && "$3" != *.ans ]]; then
            echo "Error: output file type error, $3 is neither txt, out, nor ans" >&2
            return 1
        fi
        # 从输入文件重定向，同时输出到屏幕和输出文件
        "./$1" < "$2" | tee "$3"
    fi
}
