#ifndef _MAIN_H
#define _MAIN_H
#include<QWidget>
#include<QPushButton>
#include<QLCDNumber>
#include<QLabel>
#include<QMovie>
#include<QMessageBox>
//#include "lcdrange.h"
//#include "plat.h"

class MyMainWindow;
class MyWindow:public QWidget
{
Q_OBJECT public:
  MyWindow (QWidget * parent = 0);

private:
  MyMainWindow * mymainwindow;
  QPushButton *bquit;
  QPushButton *bnewgame;
  QPushButton *boverleep;
  QLCDNumber *lcd1;
  QLCDNumber *lcd2;
  QLabel *label1;
  QLabel *label2;
  QLabel *label3;
  QLabel *label4;
  QMovie *movie1;
  QMovie *movie2;
  QMessageBox *messagebox;

  public slots:void NewGame ();

  //   void OverLeep();
  void RedWork ();
  void GreenWork ();
  void WinResult (int result);

};

#endif
