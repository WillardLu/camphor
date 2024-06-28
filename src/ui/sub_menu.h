// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#ifndef QT_MAINWINDOW_SRC_UI_SUB_MENU_
#define QT_MAINWINDOW_SRC_UI_SUB_MENU_

#include <mountain_town/string/toml.h>

#include <QFile>
#include <QLabel>
#include <QMessageBox>
#include <QPainter>
#include <QWidget>

#include "sub_menu_label.h"

class SubMenu : public QWidget {
  Q_OBJECT

 public:
  explicit SubMenu(QWidget *parent = nullptr);
  ~SubMenu();

 protected:
  void paintEvent(QPaintEvent *event) override;

 private:
  SubMenuLabel *menu_item_[10];

  friend class MainWindow;
};

#endif  // QT_MAINWINDOW_SRC_UI_SUB_MENU_