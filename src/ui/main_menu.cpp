// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.
#include "main_menu.h"

MainMenu::MainMenu(QWidget *parent) : QWidget(parent) {
  setAttribute(Qt::WA_DeleteOnClose);
  setFixedWidth(200);
}

MainMenu::~MainMenu() {}