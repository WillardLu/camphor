// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#ifndef QT_MAINWINDOW_SRC_TOOLS_GENERAL_H_
#define QT_MAINWINDOW_SRC_TOOLS_GENERAL_H_

#include <filesystem>
#include <toml/toml.hpp>

std::string GetConfig(toml::value &data, const std::string &file_name,
                      const std::string &table_name,
                      const std::string &key_name);

#endif  // QT_MAINWINDOW_SRC_TOOLS_GENERAL_H_