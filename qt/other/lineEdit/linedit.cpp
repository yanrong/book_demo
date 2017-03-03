#include <qstring.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtextstream.h>

#include "lineedit.h"

myLineEdit::myLineEdit(QWidget *parent):QMainWindow(parent)
{
    QWidget *widget=new QWidget(this);
    setCentralWidget(widget);

    QGridLayout *grid=new QGridLayout(widget);
    username=new QLineEdit("username",widget);
    password=new QLineEdit("password",widget);
    password->setEchoMode(QLineEdit::Password);

    grid->addWidget(new QLabel("Uername",widget),0,0);
    grid->addWidget(new QLabel("Password",widget),1,0);

    grid->addWidget(username,0,1);
    grid->addWidget(password,1,1);

    QPushButton *button=new QPushButton("OK",widget);
    grid->addWidget(button,2,1,Qt::AlignRight);

    connect(button,SIGNAL(clicked()),this,SLOT(Click()));

    resize(350,200);
}

void myLineEdit::Click()
{
    QTextStream out(stdout);
    out<<"username:"<<username->text()<<"\n";
    out<<"password:"<<password->text()<<"\n";
}
