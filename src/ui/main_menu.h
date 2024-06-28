// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#ifndef QT_MAINWINDOW_SRC_UI_MAIN_MENU_
#define QT_MAINWINDOW_SRC_UI_MAIN_MENU_

#include <mountain_town/string/toml.h>

#include <QFile>
#include <QLabel>
#include <QMessageBox>
#include <QPainter>
#include <QWidget>

#include "main_menu_label.h"

class MainMenu : public QWidget {
  Q_OBJECT

 public:
  explicit MainMenu(QWidget *parent = nullptr);
  ~MainMenu();

 protected:
  void paintEvent(QPaintEvent *event) override;

 private:
  QLabel *logo_;
  MainMenuLabel *menu_item_[14];

  friend class MainWindow;
};

#endif  // QT_MAINWINDOW_SRC_UI_MAIN_MENU_