#include <QApplication>
#include <QGridLayout>
#include <QLabel>
/**
*this programming test gridlayout management,QGridLaout need three parameters ,first is widget ,other two locate the widget's position,row and column
*/
int main(int argc,char *argv[])
{
    QApplication app(argc,argv);

    QWidget *window=new QWidget;

    QGridLayout *mainLayout=new QGridLayout(window) ;

    QLabel *label1=new QLabel("<h2><font color=yellow size=20>One</font></h2>");
    QLabel *label2=new QLabel("<h2><font color=blue size=10>Two</font></h2>");
    QLabel *label3=new QLabel("<h2><font color=red size=5>Three</font></h2>");
    QLabel *label4=new QLabel("<h2><font color=red size=5>Four</font></h2>");
    QLabel *label5=new QLabel("<h2><font color=red size=10>Five</font></h2>");
    QLabel *label6=new QLabel("<h2><font color=green size=20>Six</font></h2>");

    mainLayout->addWidget(label1,0,0);
    mainLayout->addWidget(label2,0,1);
    mainLayout->addWidget(label3,0,2);
    mainLayout->addWidget(label4,1,0);
    mainLayout->addWidget(label5,1,1);
    mainLayout->addWidget(label6,1,2);

    window->show();
    return app.exec();

}
