// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#include "sub_menu.h"

SubMenu::SubMenu(QWidget* parent) : QWidget(parent) {
  setAttribute(Qt::WA_DeleteOnClose);
  // 创建菜单
  for (int i = 0; i < 10; i++) {
    menu_item_[i] = new SubMenuLabel(this);
    menu_item_[i]->setText("");
    menu_item_[i]->move(50 + i * 100, 20);
    menu_item_[i]->SetIndex(i);
    menu_item_[i]->hide();
  }
}

SubMenu::~SubMenu() {}

void SubMenu::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event)
  std::unordered_map<string, string> config;
  string err = ReadSTOML("config/ui.toml", config);
  QString message = "";
  int menu_height = 50;
  string bg_color = "white;";
  if (!err.empty()) {
    message = err.c_str();
  } else {
    if (config.find("SubMenu.height") == config.end()) {
      message = "Can't find SubMenu.height in the configuration!";
    } else {
      menu_height = stoi(config["SubMenu.height"]);
    }
    if (config.find("SubMenu.bg-color") == config.end()) {
      message = "Can't find SubMenu.bg-color in the configuration!";
    } else {
      bg_color = config["SubMenu.bg-color"];
    }
  }
  if (message != "") {
    QMessageBox::warning(this, "Warning", message);
  }
  setFixedHeight(menu_height);
  string color1 = "background-color: " + bg_color + ";";
  setStyleSheet(color1.c_str());
  QPainter painter(this);
  painter.setBrush(QColor(bg_color.c_str()));
  painter.drawRect(0, 0, width(), height());
}
