#include <QApplication>
#include <QPushButton>

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    
    QPushButton bt("Quit");
    QObject::connect(&bt,&QPushButton::clicked,&QApplication::quit);
    bt.show();
    
    return app.exec();
    
}
