// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#ifndef QT_MAINWINDOW_SRC_UI_DATA_MANAGEMENT_
#define QT_MAINWINDOW_SRC_UI_DATA_MANAGEMENT_

#include <QComboBox>
#include <QDate>
#include <QFileDialog>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPainter>
#include <QPushButton>
#include <QWidget>

#include "work_label.h"

class DataManagement : public QWidget {
  Q_OBJECT

 public:
  explicit DataManagement(QWidget *parent = nullptr);
  ~DataManagement();

 protected:
  void paintEvent(QPaintEvent *event) override;

 private slots:
  void OpenFolder();

 private:
  QLabel *items_[7];
  QComboBox *combo_box_[2];
  QLineEdit *line_edit_[3];
  QPushButton *buttons_[6];
  QListWidget *data_list_;
};

#endif  // QT_MAINWINDOW_SRC_UI_DATA_MANAGEMENT_