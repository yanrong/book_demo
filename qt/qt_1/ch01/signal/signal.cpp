#include <QApplication>
#include <QPushButton>

int main(int argc,char *argv[])
{
    QApplication a(argc,argv);

    QPushButton *btn=new QPushButton("Quit");
    QObject::connect(btn,SIGNAL(clicked()),&a,SLOT(quit()));

    btn->show();

    return a.exec();
}
