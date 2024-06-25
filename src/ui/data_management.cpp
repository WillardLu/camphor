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

  data_date_ = new QLabel(this);
  data_date_->setText("数据日期：");
  data_date_->move(20, 20);
  item1_ = new QLabel(this);
  item1_->setText("检治项目：");
  item1_->move(20, 50);
  item2_ = new QLabel(this);
  item2_->setText("门诊：");
  item2_->move(20, 80);
  item3_ = new QLabel(this);
  item3_->setText("住院：");
  item3_->move(20, 110);
}

DataManagement::~DataManagement() {}

void DataManagement::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event)

  QPainter painter(this);
  painter.setBrush(Qt::white);
  painter.drawRect(0, 0, width(), height());
}