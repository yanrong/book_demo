#include <QApplication>

#include "combobox.h"

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);

    DuComboBox *window=new DuComboBox();

    window->show();
    return app.exec();
}
