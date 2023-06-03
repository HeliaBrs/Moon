#ifndef SECENDPAGE_H
#define SECENDPAGE_H
#include <QtSql>
#include <QMainWindow>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlQuery>
namespace Ui {
  class SecendPage;
}

class SecendPage : public QMainWindow
{
  Q_OBJECT

public:
  explicit SecendPage(QWidget *parent = nullptr);
  ~SecendPage();

private slots:
  void on_pushButton_LogIn_clicked();

  void on_pushButton_eye_clicked();

  void on_pushButton_Newaccount_clicked();

  void on_pushButton_eye_2_clicked();

  void on_pushButton_clicked();

  void on_pushButton_verify_clicked();

public slots:
    void receivePassword(QString password);

private:
  Ui::SecendPage *ui;
  QSqlDatabase UserPasswords;
};

#endif // SECENDPAGE_H
