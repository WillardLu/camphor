// @copyright Copyright 2024 Willard Lu
//
// Use of this source code is governed by an MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT.

// 这里不能使用<>来包含头文件
#include "ui/main_window.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  MainWindow *window;
  window = new MainWindow();
  printf("test...\n");
  window->setWindowTitle("盛语智慧医院");
  window->show();

  return app.exec();
}
