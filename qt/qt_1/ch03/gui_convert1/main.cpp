#include <QApplication>
#include "byteconverdialog.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);

    byteConvertDialog *dialog=new byteConvertDialog;

    dialog->setAttribute(Qt::WA_QuitOnClose);
    dialog->show();

    return app.exec();
}
