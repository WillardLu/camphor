// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#include "main_window.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  central_widget_ = new QWidget(this);
  central_widget_->setAttribute(Qt::WA_DeleteOnClose);
  setCentralWidget(central_widget_);
  GetConfig();

  main_layout_ = new QHBoxLayout(central_widget_);
  // 创建左侧主菜单栏
  main_menu_ = new MainMenu(this->central_widget_);
  for (int i = 0; i < 14; i++) {
    int label_index = main_menu_->menu_item_[i]->GetIndex();
    // label_index的值为-1时表示未使用，-2时表示是退出标签。
    if (label_index == -1) break;
    if (label_index >= 0) {
      connect(main_menu_->menu_item_[i], &MainMenuLabel::SendIndex, this,
              &MainWindow::ReceiveFromMainMenu);
    } else {
      connect(main_menu_->menu_item_[i], &MainMenuLabel::SendIndex, this,
              &MainWindow::close);
      break;
    }
  }

  // 创建顶部子菜单栏并建立信号连接
  sub_menu_ = new SubMenu(central_widget_);
  for (int i = 0; i < 10; i++) {
    connect(sub_menu_->menu_item_[i], &SubMenuLabel::SendIndex, this,
            &MainWindow::ReceiveFromSubMenu);
  }

  left_layout_ = new QVBoxLayout();
  right_layout_ = new QVBoxLayout();
  left_layout_->addWidget(main_menu_);
  right_layout_->addWidget(sub_menu_);
  data_management_ = new DataManagement(central_widget_);
  right_layout_->addWidget(data_management_);
  main_layout_->addLayout(left_layout_);
  main_layout_->addLayout(right_layout_);
  data_management_->show();
}

MainWindow::~MainWindow() { this->deleteLater(); }

/// @brief 接收来自主菜单标签的信号
/// @param index 主菜单标签索引
void MainWindow::ReceiveFromMainMenu(int index) {
  if (index == active_main_menu_) return;
  if (active_main_menu_ >= 0) {
    main_menu_->menu_item_[active_main_menu_]->SetColor(0);
  }
  main_menu_->menu_item_[index]->SetColor(1);
  active_main_menu_ = index;
  if (active_sub_menu_ >= 0) {
    sub_menu_->menu_item_[active_sub_menu_]->setStyleSheet("color: BLACK; ");
  }
  DrawSubMenu(index);
  repaint();
}

/// @brief 接收来自子菜单标签的信号
/// @param index 子菜单标签索引
void MainWindow::ReceiveFromSubMenu(int index) {
  if (active_sub_menu_ >= 0) {
    sub_menu_->menu_item_[active_sub_menu_]->setStyleSheet("color: BLACK; ");
  }
  sub_menu_->menu_item_[index]->setStyleSheet("color: #67AB9F; ");
  active_sub_menu_ = index;
  repaint();
}

/// @brief 绘制子菜单
/// @param index 主菜单索引号
void MainWindow::DrawSubMenu(int index) {
  const char* menu_title[14][10] = {
      {"数据管理", "绩效统计", "", "", "", "", "", "", "", ""},
      {"数据库设置", "", "", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", "", "", ""},
      {"", "", "", "", "", "", "", "", "", ""}};
  for (int i = 0; i < 10; i++) {
    sub_menu_->menu_item_[i]->setText(menu_title[index][i]);
    if (menu_title[index][i] == nullptr || *menu_title[index][i] == '\0') {
      sub_menu_->menu_item_[i]->hide();
    } else {
      sub_menu_->menu_item_[i]->show();
    }
  }
}

void MainWindow::GetConfig() {
  std::unordered_map<string, string> config;
  string err = ReadSTOML("config/ui.toml", config);
  string message = "";
  int main_window_width = 600;
  int main_window_height = 480;
  string bg_color = "background-color: black;";
  string table_name = "MainWindow";
  if (!err.empty()) {
    message = err.c_str();
  } else {
    if (config.find(table_name + ".width") == config.end()) {
      message = "Can't find " + table_name + ".width in the configuration!";
    } else {
      main_window_width = stoi(config[table_name + ".width"]);
    }

    if (config.find(table_name + ".height") == config.end()) {
      message = "Can't find " + table_name + ".height in the configuration!";
    } else {
      main_window_height = stoi(config[table_name + ".height"]);
    }

    if (config.find(table_name + ".bg_color") == config.end()) {
      message = "Can't find " + table_name + ".bg_color in the configuration!";
    } else {
      bg_color = "background-color: " + config[table_name + ".bg_color"] + ";";
    }
  }
  if (message != "") {
    QMessageBox::warning(this, "Warning", message.c_str());
  }
  resize(main_window_width, main_window_height);
  central_widget_->setStyleSheet(QString(bg_color.c_str()));
}
