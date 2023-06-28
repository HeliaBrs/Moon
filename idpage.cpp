#include "idpage.h"
#include "ui_idpage.h"
#include "QMessageBox"
#include "QDebug"
#include "secendpage.h"
#include <iostream>

using namespace std;

IDpage::IDpage(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::IDpage)
{
  ui->setupUi(this);
  //وصل شده به دیتابیس برای وارد کردن یوزرنیم (id)
  {//datbase : sqlite
   UserPasswords = QSqlDatabase::addDatabase("QSQLITE");
   UserPasswords.setDatabaseName("/Users/helia/Moon/UserPasswords.db");

   if(!UserPasswords.open()){
       qDebug() << "Failed To Connet Database!(creating ID(ID page))";
     }
   else {
       //چک کردن این که در دیتابیس ستون مربوط به یوزرنیم موجود باشد در غیر این صورت ایجاد یک ستون
       QSqlQuery query;
       query.exec("PRAGMA table_info(mytable)");
       bool columnExists = false;
       while (query.next()) {
           QString columnName = query.value(1).toString();
           if (columnName == "userID") {
               columnExists = true;
               break;
               qDebug() << "There is one database for ID";
           }
       }
       if (!columnExists) {
           query.exec("ALTER TABLE UserPasswords ADD COLUMN userID INTEGER");
             qDebug()  << "Create one database for ID";
       }

     }
   }
}
void IDpage::on_pushButton_clicked()
{
  // چک کردن اینکه یوزنیم که وارد می شود قبلا استفاده نشده باشد

    QString userIDnew;
    userIDnew = ui->lineEdit->text();
    QSqlQuery qry;
    if(qry.exec("select * from UserPasswords where userID='"+userIDnew+"'"))
      {
        int number = 0;
        while(qry.next())
          {
            number++;
          }//تعداد موارد تطبیق داده شده
        if(number>0){//در صورتی که پیدا شد
            QMessageBox::warning(this ,
                                  "Same UserID found!" ,
                                  "Yuor UserID already exict!",
                                   "Please try another one");
          }
        else if(number==0){
            emit returnToSecondPageID(userIDnew);
            this->close();
          }
      }
}
IDpage::~IDpage()
{
  delete ui;
}
