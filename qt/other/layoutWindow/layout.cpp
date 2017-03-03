#include <QApplication>
#include <QLabel>
#include <qlayout.h>

#include "layout.h"

Layout::Layout(QWidget *parent):QMainWindow(parent)
{
    this->setWindowTitle("Layouts");

    QWidget *widget=new QWidget(this);
    setCentralWidget(widget);

    QHBoxLayout *horizontal=new QHBoxLayout(widget);
    QVBoxLayout *vertical=new QVBoxLayout();

    QLabel *label1=new QLabel("top",widget);
    QLabel *label2=new QLabel("bottom",widget);
    QLabel *label3=new QLabel("right",widget);

    vertical->addWidget(label1);
    vertical->addWidget(label2);
    horizontal->addLayout(vertical);
    horizontal->addWidget(label3);

    resize(150,100);
}

int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    Layout *window=new Layout;

    window->show();
    return app.exec();
}
