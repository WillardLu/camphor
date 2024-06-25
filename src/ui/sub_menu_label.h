// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#ifndef CAMPHOR_SRC_UI_LABELS_H
#define CAMPHOR_SRC_UI_LABELS_H

#include <QLabel>
#include <QMouseEvent>
#include <QPalette>

class SubMenuLabel : public QLabel {
  Q_OBJECT

 public:
  SubMenuLabel(QWidget *parent = nullptr);
  ~SubMenuLabel();
  void SetIndex(int index) { this->index_ = index; };

 signals:
  void SendIndex(int index);

 protected:
  void mouseReleaseEvent(QMouseEvent *event) override;

 private:
  int index_ = 0;
};

#endif  // CAMPHOR_SRC_UI_LABELS_H