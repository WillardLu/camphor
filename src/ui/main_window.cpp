// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#include "main_window.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  // 创建中心区
  this->resize(1200, 800);
  this->central_widget_ = new QWidget(this);
  // this->central_widget_->setAttribute(Qt::WA_DeleteOnClose);
  setCentralWidget(central_widget_);
  this->central_widget_->setStyleSheet(QString("background-color: #E6E6E6;"));
  main_layout_ = new QHBoxLayout(central_widget_);

  // 创建左侧主菜单栏
  main_menu_ = new QWidget(this->central_widget_);
  main_menu_->setAttribute(Qt::WA_DeleteOnClose);
  main_menu_->setFixedWidth(200);
  main_menu_->setStyleSheet(QString("background-color: WHITE;"));
  // 创建图片标签
  this->logo_ = new QLabel(this->main_menu_);
  // this->logo_->setAttribute(Qt::WA_DeleteOnClose);
  //  判断图像文件是否存在
  QString logo_file("my_logo.png");
  if (QFile::exists(logo_file)) {
    qDebug("Studio logo image file exists.\n");
    QPixmap pixmap(logo_file);
    pixmap = pixmap.scaledToWidth(100, Qt::SmoothTransformation);
    this->logo_->setPixmap(pixmap);
    this->logo_->move(50, 20);
    this->logo_->setAlignment(Qt::AlignCenter);
  } else {
    qDebug("Studio logo image file does not exist.\n");
  }

  qDebug("step1...\n");

  // 创建主菜单
  /*
  const char* menu_title[14] = {
      "概览",     "物价管理",   "门急诊挂号",     "住院登记", "财务结算",
      "药库管理", "电子病历",   "影像归档和通信", "实验室",   "临床决策支持",
      "智能运营", "互联网医院", "系统设置",       "退出"};
  */

  const char* menu_title[14] = {"财务结算", "系统设置", "退出", "", "", "", "",
                                "",         "",         "",     "", "", "", ""};
  for (int i = 0; i < 14; i++) {
    if (menu_title[i] == nullptr || *menu_title[i] == '\0') break;
    main_menu_label_[i] = new MainMenuLabel(main_menu_);
    main_menu_label_[i]->setText(menu_title[i]);
    main_menu_label_[i]->move(10, 140 + i * 40);
    main_menu_label_[i]->SetIndex(i);
    if (strcmp(menu_title[i], "退出") != 0) {
      connect(main_menu_label_[i], &MainMenuLabel::SendIndex, this,
              &MainWindow::ReceiveFromMainMenu);
    } else {
      connect(main_menu_label_[i], &MainMenuLabel::SendIndex, this,
              &MainWindow::close);
    }
  }

  // 创建顶部子菜单栏
  sub_menu_ = new QWidget(central_widget_);
  sub_menu_->setAttribute(Qt::WA_DeleteOnClose);
  sub_menu_->setFixedHeight(50);
  sub_menu_->setStyleSheet("background-color: #FFFFFF;");
  for (int i = 0; i < 10; i++) {
    sub_menu_label_[i] = new SubMenuLabel(sub_menu_);
    sub_menu_label_[i]->setText("");
    sub_menu_label_[i]->move(50 + i * 100, 20);
    sub_menu_label_[i]->SetIndex(i);
    sub_menu_label_[i]->hide();
    connect(sub_menu_label_[i], &SubMenuLabel::SendIndex, this,
            &MainWindow::ReceiveFromSubMenu);
  }

  // 创建工作区
  // workspace_ = new QWidget(central_widget_);
  // workspace_->setAttribute(Qt::WA_DeleteOnClose);
  // workspace_->setStyleSheet("background-color: #FFF0FF;");

  // 各个功能窗口

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
  main_menu_label_[active_main_menu_]->setStyleSheet("color: BLACK; ");
  main_menu_label_[index]->setStyleSheet(" color: #C00000; ");
  active_main_menu_ = index;
  if (active_sub_menu_ >= 0) {
    sub_menu_label_[active_sub_menu_]->setStyleSheet("color: BLACK; ");
  }
  DrawSubMenu(index);
  repaint();
}

/// @brief 接收来自子菜单标签的信号
/// @param index 子菜单标签索引
void MainWindow::ReceiveFromSubMenu(int index) {
  if (active_sub_menu_ >= 0) {
    sub_menu_label_[active_sub_menu_]->setStyleSheet("color: BLACK; ");
  }
  sub_menu_label_[index]->setStyleSheet(" color: BLUE; ");
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
    sub_menu_label_[i]->setText(menu_title[index][i]);
    if (menu_title[index][i] == nullptr || *menu_title[index][i] == '\0') {
      sub_menu_label_[i]->hide();
    } else {
      sub_menu_label_[i]->show();
    }
  }
}