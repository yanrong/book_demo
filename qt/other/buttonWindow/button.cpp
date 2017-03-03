#include "button.h"
#include <QPushButton>
#include <QApplication>
#include <iostream>

ButtonWindow::ButtonWindow(QWidget *parent):QMainWindow(parent)
{
    this->setWindowTitle("this is the window title");
    QPushButton *button=new QPushButton("Clicked Me!");
    button->setGeometry(50,30,70,20);
    button->setParent(this);
    connect(button,SIGNAL(clicked()),this,SLOT(Clicked()));
}

void ButtonWindow::Clicked()
{
    std::cout<<"I will fuck you!\n";
}

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    ButtonWindow *window=new ButtonWindow();

    window->show();
    return app.exec();
}
