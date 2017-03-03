#include "lineedit.h"
#include <qapplication.h>

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    myLineEdit *window=new myLineEdit();

    window->show();
    return app.exec();
}
