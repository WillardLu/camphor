cmake_minimum_required(VERSION 3.20)

project(camphor LANGUAGES CXX)

# 目前的 GoogleTest 至少需要 C++14
set(CMAKE_CXX_STANDARD 17)
# 这里表示在编译时，使用 C++17 标准，但不会强制要求源码也使用 C++17
# 注意：这里设置的是编译时的 C++ 标准，而不是运行时的 C++ 标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 禁用编译器特定的扩展，确保代码的可移植性，因为它避免了依赖于特定编译器的语法或特性。
set(CMAKE_CXX_EXTENSIONS OFF)

# 启用GCC所有警告，视警告为错误
# -fopenmp 表示启用OpenMP支持，如果不需要并行，可以去掉
# -Werror 表示将所有警告视为错误
# -Wall -Wextra 表示启用额外的警告
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -fopenmp")

# 使用enable_testing()后，在build目录中会生成一个Testing文件夹，
# 里面包含测试函数的实现。然后在build目录下执行ctest命令才生效。
# 注意：在执行ctest命令时，需要进入build目录，而不是项目根目录。
# 这里的测试内容与 add_test 设置有关。
enable_testing()
add_subdirectory(src)
add_subdirectory(tests)