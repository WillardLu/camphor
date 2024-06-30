// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#ifndef QT_MAINWINDOW_SRC_UI_WORK_LABEL_H_
#define QT_MAINWINDOW_SRC_UI_WORK_LABEL_H_

#include <QLabel>

class WorkLabel : public QLabel {
 public:
  WorkLabel(QWidget *parent = nullptr);
  ~WorkLabel();
};

#endif  // QT_MAINWINDOW_SRC_UI_WORK_LABEL_H_