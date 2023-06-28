#ifndef IDPAGE_H
#define IDPAGE_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QtDebug>
#include <QFileInfo>
#include <QtSql>

namespace Ui {
  class IDpage;
}

class IDpage : public QMainWindow
{
  Q_OBJECT

public:
  explicit IDpage(QWidget *parent = nullptr);
  ~IDpage();

private slots:

  void on_pushButton_clicked();

public:signals:
   void returnToSecondPageID(QString userID);

private:
  Ui::IDpage *ui;
  QSqlDatabase UserPasswords;
};

#endif // IDPAGE_H
