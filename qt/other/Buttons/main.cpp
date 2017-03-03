#include <QApplication>

#include "buttons.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    Buttons *window=new Buttons;
    window->show();
    return app.exec();
}
