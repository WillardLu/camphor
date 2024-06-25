find_package(GTest REQUIRED)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable(camphor_test
  main_test.cpp
  data_management/excel_to_pg_test.cpp
  ${PROJECT_SOURCE_DIR}/lib/mountain_town/string/basic.cpp
  ${PROJECT_SOURCE_DIR}/src/data_management/excel_to_pg.cpp)

target_link_libraries(camphor_test
 PRIVATE
  GTest::GTest
  ${PROJECT_SOURCE_DIR}/third-party/xlsxio/xlsxio_read.dll
  ${PROJECT_SOURCE_DIR}/third-party/pqxx/libpq.dll)

# 通过下面的设置，就可以不用在 main_test.cpp 中包含 mnist.cpp 的相对路径了，
# 因为 CMake 会自动把 mnist.cpp 添加到 rock_solid_test 的链接库中。
target_include_directories(camphor_test
 PUBLIC
  ${PROJECT_SOURCE_DIR}/src/
  ${PROJECT_SOURCE_DIR}/lib/
  ${PROJECT_SOURCE_DIR}/third-party/)

# add_test(NAME LoadMnist COMMAND rock_solid_test 1)
