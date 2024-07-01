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

  QFont font0;
  font0.setPointSize(11);
  // 1、设置标签
  QString item_title[7] = {
      "数据日期：", "检治项目：", "        门诊：",      "        住院：",
      "年",         "月",         "数据库中已有数据列表"};
  int item_width[7] = {80, 80, 80, 80, 20, 20, 160};
  int item_height[7] = {20, 20, 20, 20, 20, 20, 100};
  int item_x[7] = {20, 20, 20, 20, 180, 250, 20};
  int item_y[7] = {20, 60, 90, 120, 20, 20, 220};
  for (int i = 0; i <= 6; i++) {
    items_[i] = new QLabel(this);
    items_[i]->setFont(font0);
    items_[i]->setText(item_title[i]);
    items_[i]->setFixedSize(item_width[i], item_height[i]);
    items_[i]->setAlignment(Qt::AlignLeft);
    items_[i]->move(item_x[i], item_y[i]);
  }

  // 2、设置下拉框
  combo_box_[0] = new QComboBox(this);
  combo_box_[0]->setFont(font0);
  combo_box_[0]->setFixedSize(80, 28);
  combo_box_[0]->move(100, 14);
  for (int i = 1990; i < 2080; i++) {
    combo_box_[0]->addItem(QString::number(i));
  }
  // 计算当前的年去设置combo_box_[0]的值
  combo_box_[0]->setCurrentIndex(
      combo_box_[0]->findText(QString::number(QDate::currentDate().year())));

  combo_box_[1] = new QComboBox(this);
  combo_box_[1]->setFont(font0);
  combo_box_[1]->setFixedSize(50, 28);
  combo_box_[1]->move(210, 14);
  for (int i = 1; i <= 12; i++) {
    combo_box_[1]->addItem(QString::number(i));
  }
  // 计算当前的月去设置combo_box_[1]的值
  combo_box_[1]->setCurrentIndex(
      combo_box_[1]->findText(QString::number(QDate::currentDate().month())));

  // 3、设置单行编辑框
  int line_edit_width[3] = {500, 500, 500};
  int line_edit_x[3] = {100, 100, 100};
  int line_edit_y[3] = {60, 90, 120};
  for (int i = 0; i <= 2; i++) {
    line_edit_[i] = new QLineEdit(this);
    line_edit_[i]->setFixedSize(line_edit_width[i], 20);
    line_edit_[i]->move(line_edit_x[i], line_edit_y[i]);
    line_edit_[i]->setFont(font0);
    line_edit_[i]->setAlignment(Qt::AlignLeft);
    line_edit_[i]->setReadOnly(true);
  }

  QFont font1;
  font1.setPointSize(12);
  // 4、设置按钮
  QString button_title[6] = {"选择文件", "选择文件", "选择文件",
                             "导入数据", "替换数据", "删除数据"};
  int button_width[6] = {100, 100, 100, 120, 120, 120};
  int button_height[6] = {28, 28, 28, 36, 36, 36};
  int button_x[6] = {610, 610, 610, 20, 160, 300};
  int button_y[6] = {60, 90, 120, 160, 160, 160};
  for (int i = 0; i <= 5; i++) {
    buttons_[i] = new QPushButton(this);
    // 设置按钮为3D风格
    buttons_[i]->setFlat(false);
    buttons_[i]->setFixedSize(button_width[i], button_height[i]);
    buttons_[i]->move(button_x[i], button_y[i]);
    buttons_[i]->setFont(font0);
    buttons_[i]->setText(button_title[i]);
    buttons_[i]->setCursor(Qt::PointingHandCursor);
    if (i >= 3) {
      buttons_[i]->setFont(font1);
      buttons_[i]->setStyleSheet("color: #A20025;");
      continue;
    }
    connect(buttons_[i], &QPushButton::clicked, this,
            &DataManagement::OpenFolder);
  }

  // 5、设置列表
  data_list_ = new QListWidget(this);
  data_list_->setFixedSize(680, 450);
  data_list_->setFont(font0);
  data_list_->move(20, 250);
  data_list_->setEditTriggers(QAbstractItemView::NoEditTriggers);
  data_list_->setSpacing(6);
  // 设置选中行的背景色
  data_list_->setStyleSheet(
      "QListWidget::item:selected{background-color: #67AB9F; color: white;}");
  // 设置外边框样式为实线
  data_list_->setFrameStyle(QFrame::Box | QFrame::Plain);

  // 向QListWidget插入数据
  data_list_->insertItem(0, new QListWidgetItem("2024-03  检治项目数据"));
  data_list_->insertItem(1, new QListWidgetItem("2024-03  住院数据"));
  data_list_->insertItem(2, new QListWidgetItem("2024-03  门诊数据"));
}

DataManagement::~DataManagement() {}

void DataManagement::paintEvent(QPaintEvent* event) {
  Q_UNUSED(event)

  QPainter painter(this);
  painter.setBrush(Qt::white);
  painter.drawRect(0, 0, width(), height());
}

void DataManagement::OpenFolder() {
  QObject* senderObj = sender();
  int index = -1;
  if (senderObj == buttons_[0]) {
    index = 0;
  } else if (senderObj == buttons_[1]) {
    index = 1;
  } else if (senderObj == buttons_[2]) {
    index = 2;
  }

  QString file_name = QFileDialog::getOpenFileName(this, tr("选择数据文件"));
  if (!file_name.isEmpty()) {
    line_edit_[index]->setText(file_name);
    line_edit_[index]->repaint();
  }
}
