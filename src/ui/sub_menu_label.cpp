// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#include "sub_menu_label.h"

SubMenuLabel::SubMenuLabel(QWidget* parent) : QLabel(parent) {
  this->setAttribute(Qt::WA_DeleteOnClose);
  this->setFixedSize(80, 20);
  this->setStyleSheet("background-color: transparent;");
  QFont font;
  font.setFamily("Microsoft YaHei");
  font.setPointSize(11);
  this->setFont(font);
  this->setAlignment(Qt::AlignCenter);
  this->setCursor(Qt::PointingHandCursor);
}

SubMenuLabel::~SubMenuLabel() {}

void SubMenuLabel::mouseReleaseEvent(QMouseEvent* event) {
  if (event->button() == Qt::LeftButton) {
    emit this->SendIndex(this->index_);
  }
}