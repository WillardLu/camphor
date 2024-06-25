# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 似乎Qt6并不能识别EXECUTABLE_OUTPUT_PATH，所以暂时使用CMAKE_BINARY_DIR
# 设置可执行文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(PROJECT_NAME camphor)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 查找 Qt6 并导入模块。如果 CMake 找不到模块，就没有必要继续，
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Gui)

# 为典型的 Qt 应用程序设置整个项目的默认值。
qt_standard_project_setup()

# 加上WIN32参数声明这是一个窗口，就不会同时显示命令行窗口了。
add_executable(${PROJECT_NAME}
  main.cpp
  ui/data_management.cpp
  ui/main_menu_label.cpp
  ui/main_window.cpp
  ui/sub_menu_label.cpp)

target_include_directories(${PROJECT_NAME}
 PUBLIC
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/lib/
  ${CMAKE_SOURCE_DIR}/third-party/)

target_link_libraries(${PROJECT_NAME}
 PRIVATE
  # 下面不能使用${PROJECT_SOURCE_DIR}，因为Qt不识别
  ${CMAKE_SOURCE_DIR}/third-party/xlsxio/xlsxio_read.dll
  ${CMAKE_SOURCE_DIR}/third-party/pqxx/libpq.dll
  Qt6::Core
  Qt6::Gui
  Qt6::Widgets)
