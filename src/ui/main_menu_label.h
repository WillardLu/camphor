// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#ifndef QT_MAINWINDOW_SRC_UI_MAIN_MENU_LABEL_
#define QT_MAINWINDOW_SRC_UI_MAIN_MENU_LABEL_

#include <QLabel>
#include <QMouseEvent>
#include <QPalette>

class MainMenuLabel : public QLabel {
  Q_OBJECT

 public:
  MainMenuLabel(QWidget *parent = nullptr);
  ~MainMenuLabel();
  void SetIndex(int index) { this->index_ = index; };
  int GetIndex() { return index_; };

 signals:
  void SendIndex(int index);

 protected:
  void mouseReleaseEvent(QMouseEvent *event) override;

 private:
  int index_ = -1;
};

#endif  // QT_MAINWINDOW_SRC_UI_MAIN_MENU_LABEL_