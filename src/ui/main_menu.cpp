// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#include "main_menu.h"

MainMenu::MainMenu(QWidget* parent) : QWidget(parent) {
  setAttribute(Qt::WA_DeleteOnClose);
  GetConfig();
  logo_ = new QLabel(this);
  logo_->setAttribute(Qt::WA_DeleteOnClose);
  //  判断图像文件是否存在
  QString logo_file("resource/my_logo.png");
  if (QFile::exists(logo_file)) {
    QPixmap pixmap(logo_file);
    pixmap = pixmap.scaledToWidth(logo_width_, Qt::SmoothTransformation);
    logo_->setPixmap(pixmap);
    logo_->move(logo_x_, logo_y_);
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
    menu_item_[i]->move(item_left_margin_,
                        item_top_margin_ + i * item_row_spacing_);
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

  QPainter painter(this);
  painter.setBrush(QColor(bg_color_));
  painter.drawRect(0, 0, width(), height());
}

void MainMenu::GetConfig() {
  std::unordered_map<string, string> config;
  string err = ReadSTOML("config/ui.toml", config);
  string message = "";
  int main_menu_width = 200;
  string bg_color = "white";
  int logo_width = 100;
  int logo_x = 50;
  int logo_y = 20;
  int item_left_margin = 10;
  int item_top_margin = 140;
  int item_row_spacing = 40;
  string table_name = "MainMenu";
  if (!err.empty()) {
    message = err.c_str();
  } else {
    if (config.find(table_name + ".width") == config.end()) {
      message = "Can't find " + table_name + ".width in the configuration!";
    } else {
      main_menu_width = stoi(config[table_name + ".width"]);
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
    if (config.find(table_name + ".item_row_spacing") == config.end()) {
      message = "Can't find " + table_name +
                ".item_row_spacing in the configuration!";
    } else {
      item_row_spacing = stoi(config[table_name + ".item_row_spacing"]);
    }
    if (config.find(table_name + ".logo_width") == config.end()) {
      message =
          "Can't find " + table_name + ".logo_width in the configuration!";
    } else {
      logo_width = stoi(config[table_name + ".logo_width"]);
    }
    if (config.find(table_name + ".logo_x") == config.end()) {
      message = "Can't find " + table_name + ".logo_x in the configuration!";
    } else {
      logo_x = stoi(config[table_name + ".logo_x"]);
    }
    if (config.find(table_name + ".logo_y") == config.end()) {
      message = "Can't find " + table_name + ".logo_y in the configuration!";
    } else {
      logo_y = stoi(config[table_name + ".logo_y"]);
    }
  }
  if (message != "") {
    QMessageBox::warning(this, "Warning", message.c_str());
  }
  setFixedWidth(main_menu_width);
  bg_color_ = bg_color.c_str();
  setStyleSheet(("background-color: " + bg_color + ";").c_str());
  logo_width_ = logo_width;
  logo_x_ = logo_x;
  logo_y_ = logo_y;
  item_left_margin_ = item_left_margin;
  item_top_margin_ = item_top_margin;
  item_row_spacing_ = item_row_spacing;
}