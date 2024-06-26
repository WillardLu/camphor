// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#include <gtest/gtest.h>
#include <tools/general.h>

using std::cout;
using std::endl;

TEST(GENERAL_Tests, GetConfig) {
  const std::string toml_file = "tests/tools/testdata/test1.toml";
  std::string error;
  // 文件名为空的错误测试
  toml::value data;
  error = GetConfig(data, "", "test", "test");
  EXPECT_NE(error, "");
  // 键名为空的错误测试
  error = GetConfig(data, toml_file, "test", "");
  EXPECT_NE(error, "");
  // 文件名不正确的错误测试
  error = GetConfig(data, "tests/t1.toml", "test", "test");
  EXPECT_NE(error, "");
  // 普通测试一
  error = GetConfig(<std::string>data, toml_file, "", "test");
  EXPECT_EQ(data, "data");
}