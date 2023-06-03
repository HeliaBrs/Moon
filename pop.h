#ifndef POP_H
#define POP_H

#include <QMainWindow>

namespace Ui {
  class pop;
}

class pop : public QMainWindow
{
  Q_OBJECT

public:
  explicit pop(QWidget *parent = nullptr);
  ~pop();

private slots:
  void on_pushButton_clicked();

signals:
    void returnToSecondPage(QString password);

private:
  Ui::pop *ui;
};

#endif // POP_H
