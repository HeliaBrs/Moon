#ifndef IDPAGE_H
#define IDPAGE_H

#include <QMainWindow>

namespace Ui {
  class IDpage;
}

class IDpage : public QMainWindow
{
  Q_OBJECT

public:
  explicit IDpage(QWidget *parent = nullptr);
  ~IDpage();

private:
  Ui::IDpage *ui;
};

#endif // IDPAGE_H
