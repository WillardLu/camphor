// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#include "sub_menu.h"

SubMenu::SubMenu(QWidget* parent) : QWidget(parent) {
  setAttribute(Qt::WA_DeleteOnClose);
  GetConfig();
  // 创建菜单
  for (int i = 0; i < 10; i++) {
    menu_item_[i] = new SubMenuLabel(this);
    menu_item_[i]->setText("");
    menu_item_[i]->move(item_left_margin_ + i * item_column_spacing_,
                        item_top_margin_);
    menu_item_[i]->SetIndex(i);
    menu_item_[i]->hide();
  }
}

SubMenu::~SubMenu() {}

void SubMenu::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event)

  QPainter painter(this);
  painter.setBrush(QColor(bg_color_));
  painter.drawRect(0, 0, width(), height());
}

void SubMenu::GetConfig() {
  std::unordered_map<string, string> config;
  string err = ReadSTOML("config/ui.toml", config);
  string message = "";
  int menu_height = 50;
  string bg_color = "white;";
  int item_left_margin = 50;
  int item_top_margin = 20;
  int item_column_spacing = 40;
  string table_name = "SubMenu";
  if (!err.empty()) {
    message = err.c_str();
  } else {
    if (config.find(table_name + ".height") == config.end()) {
      message = "Can't find " + table_name + ".height in the configuration!";
    } else {
      menu_height = stoi(config[table_name + ".height"]);
    }
    if (config.find(table_name + ".bg_color") == config.end()) {
      message = "Can't find " + table_name + ".bg_color in the configuration!";
    } else {
      bg_color = config[table_name + ".bg_color"];
    }
    if (config.find(table_name + ".item_left_margin") == config.end()) {
      message = "Can't find " + table_name +
                ".item_left_margin in the configuration!";
    } else {
      item_left_margin = stoi(config[table_name + ".item_left_margin"]);
    }
    if (config.find(table_name + ".item_top_margin") == config.end()) {
      message =
          "Can't find " + table_name + ".item_top_margin in the configuration!";
    } else {
      item_top_margin = stoi(config[table_name + ".item_top_margin"]);
    }
    if (config.find(table_name + ".item_column_spacing") == config.end()) {
      message = "Can't find " + table_name +
                ".item_column_spacing in the configuration!";
    } else {
      item_column_spacing = stoi(config[table_name + ".item_column_spacing"]);
    }
  }
  if (message != "") {
    QMessageBox::warning(this, "Warning", message.c_str());
  }
  setFixedHeight(menu_height);
  bg_color_ = bg_color.c_str();
  string color1 = "background-color: " + bg_color + ";";
  setStyleSheet(color1.c_str());
  item_left_margin_ = item_left_margin;
  item_top_margin_ = item_top_margin;
  item_column_spacing_ = item_column_spacing;
}