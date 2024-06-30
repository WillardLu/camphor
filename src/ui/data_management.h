// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#ifndef QT_MAINWINDOW_SRC_UI_DATA_MANAGEMENT_
#define QT_MAINWINDOW_SRC_UI_DATA_MANAGEMENT_

#include <QLabel>
#include <QPainter>
#include <QWidget>

#include "work_label.h"

class DataManagement : public QWidget {
  Q_OBJECT

 public:
  explicit DataManagement(QWidget *parent = nullptr);
  ~DataManagement();

 protected:
  void paintEvent(QPaintEvent *event) override;

 private:
  WorkLabel *items_[4];
};

#endif  // QT_MAINWINDOW_SRC_UI_DATA_MANAGEMENT_