// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

#include "work_label.h"

WorkLabel::WorkLabel(QWidget* parent) : QLabel(parent) {
  this->setAttribute(Qt::WA_DeleteOnClose);
  this->setAlignment(Qt::AlignCenter);
  QFont font;
  font.setPointSize(10);
  setFont(font);
}

WorkLabel::~WorkLabel() {}
