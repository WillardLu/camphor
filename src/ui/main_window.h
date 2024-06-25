// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#ifndef QT_MAINWINDOW_SRC_UI_MAIN_WINDOW_
#define QT_MAINWINDOW_SRC_UI_MAIN_WINDOW_

#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QHBoxLayout>
#include <QLabel>
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
#include "main_menu_label.h"
#include "sub_menu_label.h"

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
  // 中心控件与主布局
  QWidget *central_widget_;
  QHBoxLayout *main_layout_;
  // 主菜单
  QWidget *main_menu_;
  QLabel *logo_;
  MainMenuLabel *main_menu_label_[14];
  // 子菜单
  QWidget *sub_menu_;
  SubMenuLabel *sub_menu_label_[10];
  // 左右布局
  QVBoxLayout *left_layout_;
  QVBoxLayout *right_layout_;
  // 工作区
  QWidget *workspace_;
  DataManagement *data_management_;
  // 活动菜单项索引
  int active_main_menu_ = -1;
  int active_sub_menu_ = -1;
};

#endif  // QT_MAINWINDOW_SRC_UI_MAIN_WINDOW_