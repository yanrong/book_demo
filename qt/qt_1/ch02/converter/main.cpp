#include <QApplication>
#include "converter.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    ConverterDialog *dialog=new ConverterDialog;

    dialog->setAttribute(Qt::WA_QuitOnClose);
    dialog->show();
    return app.exec();
}
