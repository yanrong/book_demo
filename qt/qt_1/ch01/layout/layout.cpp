#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc,char *argv[])
{
    QApplication a(argc,argv);

    QWidget window;

    QVBoxLayout *mainLayout=new QVBoxLayout(&window);
    ///QVBoxLayout *mainLayout=new QVBoxLayout(&window);
    QLabel *label1=new QLabel("<h1>One</h1>");
    QLabel *label2=new QLabel("<h1>Two</h1>");

    mainLayout->addWidget(label1);
    mainLayout->addWidget(label2);

    ///window.setLayout(mainLayout);
    window.show();

    return a.exec();
}
