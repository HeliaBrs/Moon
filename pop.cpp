#include "pop.h"
#include "ui_pop.h"

pop::pop(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::pop)
{
  ui->setupUi(this);
}
void pop::on_pushButton_clicked()
{
      QString password = ui->lineEdit_certification->text();
      emit returnToSecondPage(password);

      this->close();
}
pop::~pop()
{
  delete ui;
}

