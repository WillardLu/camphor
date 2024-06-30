// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#include "main_menu_label.h"

MainMenuLabel::MainMenuLabel(QWidget* parent) : QLabel(parent) {
  this->setAttribute(Qt::WA_DeleteOnClose);
  GetConfig();
  this->setAlignment(Qt::AlignCenter);
  this->setCursor(Qt::PointingHandCursor);
}

MainMenuLabel::~MainMenuLabel() {}

void MainMenuLabel::GetConfig() {
  std::unordered_map<string, string> config;
  string err = ReadSTOML("config/ui.toml", config);
  string message = "";
  int width0 = 180;
  int height0 = 20;
  string color0 = "black";
  string font_name = "Microsoft YaHei";
  int font_size = 12;
  string table_name = "MainMenuLabel";
  if (!err.empty()) {
    message = err;
  } else {
    if (config.find(table_name + ".width") == config.end()) {
      message = "Can't find " + table_name + ".width in the configuration!";
    } else {
      width0 = stoi(config[table_name + ".width"]);
    }
    if (config.find("SubMenuLabel.height") == config.end()) {
      message = "Can't find " + table_name + ".height in the configuration!";
    } else {
      height0 = stoi(config["SubMenuLabel.height"]);
    }
    if (config.find("SubMenuLabel.color") == config.end()) {
      message = "Can't find " + table_name + ".color in the configuration!";
    } else {
      color0 = config["SubMenuLabel.color"];
    }
    if (config.find("SubMenuLabel.font_name") == config.end()) {
      message = "Can't find " + table_name + ".font_name in the configuration!";
    } else {
      font_name = config["SubMenuLabel.font_name"];
    }
    if (config.find("SubMenuLabel.font_size") == config.end()) {
      message = "Can't find " + table_name + ".font_size in the configuration!";
    } else {
      font_size = stoi(config["SubMenuLabel.font_size"]);
    }
  }
  if (message != "") {
    QMessageBox::warning(this, "Warning", message.c_str());
  }
  setFixedSize(width0, height0);
  color0 = "color: " + color0 + ";";
  setStyleSheet(color0.c_str());
  QFont font;
  font.setFamily(font_name.c_str());
  font.setPointSize(font_size);
  setFont(font);
  setAlignment(Qt::AlignCenter);
}

void MainMenuLabel::mouseReleaseEvent(QMouseEvent* event) {
  if (event->button() == Qt::LeftButton) {
    emit this->SendIndex(this->index_);
  }
}

void MainMenuLabel::SetColor(int state) {
  QString color0 = "";
  switch (state) {
    case 0:
      color0 = common_color_;
      break;
    case 1:
      color0 = selected_color_;
      break;
    default:
      color0 = "black";
  }
  setStyleSheet("color: " + color0 + ";");
}