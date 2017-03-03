#include <QtGui>
#include <QApplication>

#include "ui_byteConvertDialog.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    QDialog *dialog=new QDialog;
    Ui::byteConvertDialog *ui=new Ui::byteConvertDialog;
    /*directly instantiate the generated class and bind the instance to a previously
    created widget with setupUi(), here previously widget is dialog(QDialog)
    */
    ui->setupUi(dialog);
    dialog->setAttribute(Qt::WA_QuitOnClose);
    dialog->show();

    return app.exec();
}
