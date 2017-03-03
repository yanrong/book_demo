#include <QApplication>
#include "byteconvertdialog.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);

    byteConvertDialog *dialog=new byteConvertDialog;
    dialog->show();
    dialog->setAttribute(Qt::WA_QuitOnClose);

    return app.exec();
}
