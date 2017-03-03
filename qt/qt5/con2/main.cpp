#include <QApplication>
#include <QPushButton>
#include <QDebug>
/*
* for Qt5 using lambda expr
*connect a signal to a lambda exprsssion
*
*/
int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    
    QPushButton button("Quit");
    QObject::connect(&button,&QPushButton::clicked,[](bool){
       qDebug()<<"You clicked me";
    });
    
    button.show();
    
    return app.exec();
}
