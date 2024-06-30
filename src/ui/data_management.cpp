// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "data_management.h"

DataManagement::DataManagement(QWidget* parent) : QWidget(parent) {
  this->setAttribute(Qt::WA_DeleteOnClose);
  // 背景色需要setStyleSheet和paintEvent一起配合才能完整实现
  this->setStyleSheet("background-color: white;");

  QString item_title[4] = {"数据日期：", "检治项目：", "门诊：", "住院："};
  int item_x[4] = {20, 20, 20, 20};
  int item_y[4] = {20, 60, 90, 120};
  for (int i = 0; i < 4; i++) {
    items_[i] = new WorkLabel(this);
    items_[i]->setText(item_title[i]);
    items_[i]->setFixedSize(80, 20);
    items_[i]->setAlignment(Qt::AlignRight);
    items_[i]->move(item_x[i], item_y[i]);
  }
}

DataManagement::~DataManagement() {}

void DataManagement::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event)

  QPainter painter(this);
  painter.setBrush(Qt::white);
  painter.drawRect(0, 0, width(), height());
}