#include <QApplication>
#include <QPushButton>
#include <QDesktopWidget>

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    QPushButton button("push me");
    QObject::connect(&button,SIGNAL(clicked()),&app,SLOT(quit()));

    button.show();
    return app.exec();
}
