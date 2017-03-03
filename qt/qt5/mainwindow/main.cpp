#include <QApplication>
#include "mainwindow.h"
/*
* for qt5 
*/
int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    
    MainWindow window;
    window.show();
    
    return app.exec();
}
