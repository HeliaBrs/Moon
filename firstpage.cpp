#include "firstpage.h"
#include "ui_firstpage.h"
#include "secendpage.h"

FirstPage::FirstPage(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::FirstPage)
{
  ui->setupUi(this);
  ui->label_greeting->setStyleSheet("background-image:url(:/new/prefix1/welcom.jpeg);");
}

FirstPage::~FirstPage()
{
  delete ui;
}


void FirstPage::on_pushButton_Welcome_clicked()
{
    this->close();
    SecendPage * nw = new SecendPage;
    nw -> show();
}

