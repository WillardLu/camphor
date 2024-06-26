// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#include "general.h"

std::string GetConfig(toml::value &data, const std::string &file_name,
                      const std::string &table_name,
                      const std::string &key_name) {
  if (file_name.empty() || key_name.empty()) {
    return "文件名或键名不能为空。\n";
  }
  // 使用STL判断文件是否存在
  if (!std::filesystem::exists(file_name)) {
    return "配置文件不存在\n";
  }
  toml::value config;
  try {
    config = toml::parse(file_name);
  } catch (const toml::syntax_error &err) {
    return err.what();
  }

  if (table_name.empty()) {
    // 当表名为空时，意味着读取的是非表的配置参数
    data = config.at(key_name);
    return "";
  } else {
    const auto table = toml::find(config, table_name);
    data = toml::find(table, key_name);
    return "";
  }
}