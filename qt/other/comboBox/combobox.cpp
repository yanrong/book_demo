#include <QLayout>
#include <QTextStream>

#include "combobox.h"

DuComboBox::DuComboBox(QWidget *parent):QComboBox(parent)
{
    QWidget *widget=new QWidget(this);
    QVBoxLayout *vbox=new QVBoxLayout(widget);

    QComboBox *editable=new QComboBox(widget);
    editable->setEditable(true);
    vbox->addWidget(editable);

    QComboBox *readonly=new QComboBox(widget);
    readonly->setEditable(false);
    vbox->addWidget(readonly);

    static const char *items[]={"Macbelt","Twelfth Night","Othello",0};

    for(int i=0;items[i];i++)
    {
        editable->insertItem(i,items[i]);
        readonly->insertItem(i,items[i]);
    }

    connect(editable,SIGNAL(textChanged(const QString &)),this,SLOT(Changed(const QString &)));

    resize(200,250);
}

void DuComboBox::Changed(const QString &s)
{
    QTextStream cout(stdout);
    cout<<s<<"\n";
}
