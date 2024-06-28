// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#include "main_menu.h"

MainMenu::MainMenu(QWidget* parent) : QWidget(parent) {
  setAttribute(Qt::WA_DeleteOnClose);
  logo_ = new QLabel(this);
  logo_->setAttribute(Qt::WA_DeleteOnClose);
  //  判断图像文件是否存在
  QString logo_file("resource/my_logo.png");
  if (QFile::exists(logo_file)) {
    QPixmap pixmap(logo_file);
    pixmap = pixmap.scaledToWidth(100, Qt::SmoothTransformation);
    logo_->setPixmap(pixmap);
    logo_->move(50, 20);
    logo_->setAlignment(Qt::AlignCenter);
  } else {
    QMessageBox::warning(this, "Warning",
                         "Studio logo image file does not exist.",
                         QMessageBox::Ok);
  }
  // 创建主菜单
  /*
  const char* menu_title[14] = {
      "概览",     "物价管理",   "门急诊挂号",     "住院登记", "财务结算",
      "药库管理", "电子病历",   "影像归档和通信", "实验室",   "临床决策支持",
      "智能运营", "互联网医院", "系统设置",       "退出"};
  */

  const char* menu_title[14] = {"财务结算", "系统设置", "退出", "-1", "-1",
                                "-1",       "-1",       "-1",   "-1", "-1",
                                "-1",       "-1",       "-1",   "-1"};
  for (int i = 0; i < 14; i++) {
    if (menu_title[i] == nullptr || *menu_title[i] == '\0') break;
    if (strcmp(menu_title[i], "-1") == 0) break;
    menu_item_[i] = new MainMenuLabel(this);
    menu_item_[i]->setText(menu_title[i]);
    menu_item_[i]->move(10, 140 + i * 40);
    if (strcmp(menu_title[i], "退出") == 0) {
      menu_item_[i]->SetIndex(-2);
    } else {
      menu_item_[i]->SetIndex(i);
    }
  }
}

MainMenu::~MainMenu() {}

void MainMenu::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event)

  std::unordered_map<string, string> config;
  string err = ReadSTOML("config/ui.toml", config);
  QString message = "";
  int main_menu_width = 200;
  string bg_color = "white";
  if (!err.empty()) {
    message = err.c_str();
  } else {
    if (config.find("MainMenu.width") == config.end()) {
      message = "Can't find MainMenu.width in the configuration!";
    } else {
      main_menu_width = stoi(config["MainMenu.width"]);
    }
    if (config.find("MainMenu.bg-color") == config.end()) {
      message = "Can't find MainMenu.bg-color in the configuration!";
    } else {
      bg_color = config["MainMenu.bg-color"];
    }
  }
  if (message != "") {
    QMessageBox::warning(this, "Warning", message);
  }
  setFixedWidth(main_menu_width);
  string color1 = "background-color: " + bg_color + ";";
  setStyleSheet(color1.c_str());
  QPainter painter(this);
  painter.setBrush(QColor(bg_color.c_str()));
  painter.drawRect(0, 0, width(), height());
}
