#include "buttons.h"

#include <QPushButton>
#include <QLabel>
#include <QLayout>
#include <QTextStream>
#include <QButtonGroup>

Buttons::Buttons(QWidget *parent):QMainWindow(parent)
{
    QWidget *widget=new QWidget(this);
    setCentralWidget(widget);

    QVBoxLayout *vbox=new QVBoxLayout(widget);

    checkbox=new QCheckBox("checkButton",widget);
    vbox->addWidget(checkbox);

    QButtonGroup *buttongroup=new QButtonGroup;
    radiobutton1=new QRadioButton("Radio1",widget);
    buttongroup->addButton(radiobutton1);
    vbox->addWidget(radiobutton1);

    radiobutton2=new QRadioButton("Radio2",widget);
    buttongroup->addButton(radiobutton2);
    vbox->addWidget(radiobutton2);

    QPushButton *button=new QPushButton("OK",widget);
    vbox->addWidget(button);

    //resize(200,300);

    connect(button,SIGNAL(clicked()),this,SLOT(Click()));
}

void Buttons::printActive(QAbstractButton *button)
{
    QTextStream cout(stdout);
    if(button->isChecked())
        cout<<button->text()<<" is checked\n";
    else
        cout<<button->text()<<" is not checked\n";
}

void Buttons::Click()
{
    printActive(checkbox);
    printActive(radiobutton1);
    printActive(radiobutton2);

    QTextStream cout(stdout);
    cout<<"\n";
}
