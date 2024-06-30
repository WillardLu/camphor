// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#ifndef QT_MAINWINDOW_SRC_UI_MAIN_MENU_LABEL_
#define QT_MAINWINDOW_SRC_UI_MAIN_MENU_LABEL_

#include <mountain_town/string/toml.h>

#include <QLabel>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPalette>
#include <string>

using std::string;

class MainMenuLabel : public QLabel {
  Q_OBJECT

 public:
  MainMenuLabel(QWidget *parent = nullptr);
  ~MainMenuLabel();
  void SetIndex(int index) { this->index_ = index; };
  int GetIndex() { return index_; };
  void SetColor(int state);

 signals:
  void SendIndex(int index);

 protected:
  void mouseReleaseEvent(QMouseEvent *event) override;

 private:
  void GetConfig();
  int index_ = -1;
  QString common_color_ = "black";
  QString selected_color_ = "#C00000";
};

#endif  // QT_MAINWINDOW_SRC_UI_MAIN_MENU_LABEL_