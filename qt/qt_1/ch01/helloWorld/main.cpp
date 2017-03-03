#include <QApplication>
#include <QLabel>

int main(int argc,char *argv[])
{
    QApplication a(argc,argv);
    QLabel label("<h1><B><i>Hello World</i><b></h1>");
    label.show();
    return a.exec();
}
