#include <QApplication>

#include "ByteConvertDialog.h"

int main(int argc,char *argv[])
{
    QApplication apps(argc,argv);

    ByteConvertDialog *dialog=new ByteConvertDialog;

    dialog->setAttribute(Qt::WA_QuitOnClose);
    dialog->show();

    return apps.exec();
}
