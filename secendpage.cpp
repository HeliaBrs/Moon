#include "secendpage.h"
#include "ui_secendpage.h"
#include "QMessageBox"
#include "pop.h"
#include "idpage.h"

SecendPage::SecendPage(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::SecendPage)
{
  ui->setupUi(this);
  {//datbase : sqlite
   UserPasswords = QSqlDatabase::addDatabase("QSQLITE");
   UserPasswords.setDatabaseName("/Users/helia/Moon/UserPasswords.db");

   if(!UserPasswords.open()){
       qDebug() << "Failed To Connet Database!";
     }
  }
  ui->pushButton_eye->setStyleSheet("background-image:url(:/new/prefix1/onsight.jpg);");
  ui->groupBox_creat->hide();
  ui->pushButton_eye->setStyleSheet("background-image:url(:/new/prefix1/onsight.jpg);");
  ui->pushButton_eye_2->setStyleSheet("background-image:url(:/new/prefix1/onsight.jpg);");
  ui->pushButton_verify->setDisabled(true);
  ui->pushButton_verify->hide();
}
void SecendPage::on_pushButton_LogIn_clicked()//برای زمانی که طرف اکانت داره و میخواد وارد بشه :
{
    QString username , password;
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    ui->lineEdit_password->setDisabled(true);//عدم دسترسی برای جلوگیری از خطا احتمالی
    ui->lineEdit_username->setDisabled(true);

    if(!UserPasswords.open()){//در صورتی که دیتابیسی که توش اطلاعات ذخیره شدن باز نشد
        QMessageBox::warning(this ,
                            "Database Failed!" ,
                            "there has been a problem in opening database(LogIn)",
                             "OK");
        return;
      }
    QSqlQuery qry;//چک کردن نام های کاربری و رمز های عبور با اطلاعات کاربر
    if(qry.exec("select * from UserPasswords where username='"+username+"' and password='"+password+"'"))
      {
        int number = 0;
        while(qry.next())
          {
            number++;
          }//تعداد موارد تطبیق داده شده
        if(number==1){//در صورتی که پیدا شد
            QMessageBox::information(this,
                                     "signin successful",
                                     "Username and Password correct!",
                                     "ok");
            ui->pushButton_LogIn->setText("continue");
            //next page : chat page :
          }
        else if(number<1){
            QMessageBox::warning(this,
                                "signin defeated",
                                "Username and Password NOT correct!",
                                "Try Again(if you Dont have acount press Create new account)");
            ui->lineEdit_password->setDisabled(false);//اجازه دسترسی به لاین ادیت های یوزرنیم و پسورد برای امتحان مجدد
            ui->lineEdit_username->setDisabled(false);
          }
      }
}
int klid=0;//برای سوییچ کردن بین حالت های نشان پسورد در گروپ باکس لاگ این : klid = 0(onsight) , klid = 1(offsight)
void SecendPage::on_pushButton_eye_clicked()
{
 if(klid==0){
     klid=1;
     ui->pushButton_eye->setStyleSheet("background-image:url(:/new/prefix1/offsight.jpg);");
     ui->lineEdit_password->setEchoMode(QLineEdit::Password);
   }
 else if(klid==1){
     klid=0;
     ui->pushButton_eye->setStyleSheet("background-image:url(:/new/prefix1/onsight.jpg);");
     ui->lineEdit_password->setEchoMode(QLineEdit::Normal);
   }
}
void SecendPage::on_pushButton_Newaccount_clicked()//پنهان کردن صفحه لاگ این و باز کردن صفحه کریت نیو اکانت در صورت کلیک بر روی باتن
{
    ui->groupBox_login->hide();
    ui->groupBox_creat->show();
}
int klid2=0;//برای سوییچ کردن بین حالت های نشان دادن پسورد در گروپ باکس کریت نیو اکانت
void SecendPage::on_pushButton_eye_2_clicked()
{
  if(klid2==0){
      klid2=1;
      ui->pushButton_eye_2->setStyleSheet("background-image:url(:/new/prefix1/offsight.jpg);");
      ui->lineEdit_create_password->setEchoMode(QLineEdit::Password);
    }
  else if(klid2==1){
      klid2=0;
      ui->pushButton_eye_2->setStyleSheet("background-image:url(:/new/prefix1/onsight.jpg);");
      ui->lineEdit_create_password->setEchoMode(QLineEdit::Normal);
    }
}
QString usernamenew , passwordnew;//دخیره کرده اطلاعات کاربر (گلوبال تعریف شده چون در چند اسکوپ دیگر هم به کار می آید)
void SecendPage::on_pushButton_clicked()
{
    usernamenew = ui->lineEdit_create_username->text();
    passwordnew = ui->lineEdit_create_password->text();

    if(!UserPasswords.open()){
         QMessageBox::warning(this ,
                              "^^",
                              "Failed Open DAtaBase(Creat)",
                              "ok");
    }
    QSqlQuery qry;
    if(qry.exec("select * from UserPasswords where username='"+usernamenew+"'"))
      {
         int number = 0;
         while(qry.next())//چک کردن برای این که یوزرنیم دیگری شبیه این نداشته باشیم
         {
            number++;
         }
         if(number>0){
             QMessageBox::warning(this ,
                                   "Same Username found!" ,
                                   "Yuor Username already exict!",
                                    "Please try another one");
           }
         else if(number==0){
             QMessageBox::warning(this ,
                                   "" ,
                                   "Your password and username are acceptable : press verify to continue",
                                   "ok");
             ui->pushButton_verify->setDisabled(false);
             ui->pushButton_verify->show();
            }
        }
}

QString rams;//برای چک کردن رمز کپچا
void SecendPage::on_pushButton_verify_clicked()
{
      int base = random()%6;
      switch (base) {
        case 0 :
           ui->label_certifiction->setStyleSheet("background-image:url(:/new/prefix1/321404.png);");
           rams = "321404";
           break;
        case 1 :
           ui->label_certifiction->setStyleSheet("background-image:url(:/new/prefix1/163356.png);");
           rams = "163356";
           break;
        case 2 :
           ui->label_certifiction->setStyleSheet("background-image:url(:/new/prefix1/651606.png);");
           rams = "651606";
           break;
        case 3 :
           ui->label_certifiction->setStyleSheet("background-image:url(:/new/prefix1/991181.png);");
           rams = "991181";
          break;
        case 4 :
           ui->label_certifiction->setStyleSheet("background-image:url(:/new/prefix1/665648.png);");
           rams = "665648";
           break;
        case 5 :
           ui->label_certifiction->setStyleSheet("background-image:url(:/new/prefix1/742336.png);");
           rams = "742336";
           break;
         }
      pop *popup = new pop(this);//باز کردن صفحه تایید
      popup->show();
      connect(popup, SIGNAL(returnToSecondPage(QString)), this, SLOT(receivePassword(QString)));
      ui->pushButton_verify->setDisabled(true);

}
void SecendPage::receivePassword(QString password)//مقایسه کد کپچا و کدی که کاربر به سیستم داده :
{
   if(rams == password){//در صورتی که برابر بود
       if(!UserPasswords.open()){
           QMessageBox::warning(this ,
                               "Database Failed!" ,
                               "there has been a problem in opening database(Save new Information)",
                                "OK");
           return;
         }
       QSqlQuery query;//اطلاعات جدید فرد رو دخیره میکند
          query.prepare("INSERT INTO UserPasswords (username , password , userID) "
                        "VALUES (?,?,?)");
          query.addBindValue(usernamenew);
          query.addBindValue(passwordnew);
          query.exec();
       QMessageBox::information(this,
          "EveryTHingIsGoingToBeOK",
          "New Username and Password will be Saved",
          "ok");
       //open new page ID:
       IDpage * ptr = new IDpage(this);
       ptr->show();
       //کانکت کردن صفحه گرفتن ای دی با صفحه دوم :
       connect(ptr , SIGNAL(returnToSecondPageID(QString)), this, SLOT(receiveID(QString)));
     }
   else {//در غیر این صورت کاربر میتواند دوباره امتحان کند
      ui->pushButton_verify->setDisabled(false);
      QMessageBox::warning(this,
                           "EveryTHingIsNOTGoingToBeOK",
                           "Wrong Verify Please Try Again : press verify",
                           "ok");
     }
}

void SecendPage::receiveID(QString userID){
          /*
          qDebug() << userID;
          QSqlQuery query;
          query.prepare("UPDATE UserPasswords SET id = :userID WHERE username = :username AND password = :password");
          query.bindValue(":userid", userid);
          query.bindValue(":username", username);
          query.bindValue(":password", password);

          if (query.exec()) {
              qDebug() << "Id updated successfully";
          } else {
              qDebug() << "Error updating id:" << query.lastError().text();
          }*/

}
SecendPage::~SecendPage()
{
  delete ui;
}








