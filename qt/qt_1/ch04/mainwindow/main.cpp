#include <QApplication>
#include <QMainWindow>
#include <QLabel>

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    QMainWindow window;
    QLabel *label=new QLabel("<center>Central Widget</center>");

    window.setAttribute(Qt::WA_QuitOnClose);
    window.show();

    return app.exec();
}
