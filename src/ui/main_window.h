// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#ifndef QT_MAINWINDOW_SRC_UI_MAIN_WINDOW_
#define QT_MAINWINDOW_SRC_UI_MAIN_WINDOW_

#include <mountain_town/string/toml.h>

#include <QApplication>
#include <QDebug>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>
#include <filesystem>
#include <iostream>
#include <string>

#include "data_management.h"
#include "main_menu.h"
#include "sub_menu.h"
#include "sub_menu_label.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  void DrawSubMenu(int index);

 public slots:
  void ReceiveFromMainMenu(int index);
  void ReceiveFromSubMenu(int index);

 private:
  void GetConfig();
  // 中心控件与主布局
  QWidget *central_widget_;
  // 主菜单
  MainMenu *main_menu_;
  // 子菜单
  SubMenu *sub_menu_;
  // 布局
  QHBoxLayout *main_layout_;
  QVBoxLayout *left_layout_;
  QVBoxLayout *right_layout_;
  // 数据管理
  DataManagement *data_management_;
  // 活动菜单项索引
  int active_main_menu_ = -1;
  int active_sub_menu_ = -1;
};

#endif  // QT_MAINWINDOW_SRC_UI_MAIN_WINDOW_