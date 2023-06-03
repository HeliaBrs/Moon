#include "idpage.h"
#include "ui_idpage.h"

IDpage::IDpage(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::IDpage)
{
  ui->setupUi(this);
}

IDpage::~IDpage()
{
  delete ui;
}
