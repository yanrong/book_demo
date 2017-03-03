#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QIntValidator>
#include <QRegExpValidator>

#include "converter.h"

ConverterDialog::ConverterDialog()
{
    //generate more layouts for entire dialog
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QGridLayout* editLayout = new QGridLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;

    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    QLabel* decLabel = new QLabel(tr("Decimal"));
    QLabel* hexLabel = new QLabel(tr("Hex"));
    QLabel* binLabel = new QLabel(tr("Binary"));

    decEdit = new QLineEdit;
    hexEdit = new QLineEdit;
    binEdit = new QLineEdit;

    editLayout->addWidget(decLabel, 0, 0);
    editLayout->addWidget(decEdit, 0, 1);
    editLayout->addWidget(hexLabel, 1, 0);
    editLayout->addWidget(hexEdit, 1, 1);
    editLayout->addWidget(binLabel, 2, 0);
    editLayout->addWidget(binEdit, 2, 1);

    QPushButton* exitButton = new QPushButton(tr("Quit"));

    buttonLayout->addStretch();
    buttonLayout->addWidget(exitButton);

    exitButton->setDefault(true);

    //setting all  lineedit invalidator's attribute
    QIntValidator *decValidator =new QIntValidator(0, 256, decEdit);
    decEdit->setValidator(decValidator);

    QRegExpValidator *hexValidator =new QRegExpValidator(QRegExp("[0-9a-f]{1,2}"), hexEdit);
    hexEdit->setValidator(hexValidator);

    QRegExpValidator *binValidator =new QRegExpValidator(QRegExp("[01]{1,8}"), binEdit);
    binEdit->setValidator(binValidator);

    setWindowTitle(tr("Byte Converter"));

    connect(exitButton, SIGNAL(clicked()),this, SLOT(accept()));

    connect(decEdit,SIGNAL(textEdited(QString)),this,SLOT(decChanged(const QString&)));
    connect(hexEdit,SIGNAL(textEdited(QString)),this,SLOT(hexChanged(const QString&)));
    connect(binEdit,SIGNAL(textEdited(QString)),this,SLOT(binChanged(const QString&)));

    resize(230,200);
}

void ConverterDialog::decChanged(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok);
    if(ok)
    {
        hexEdit->setText(QString::number(num,16));
        binEdit->setText(QString::number(num,2));
    }
    else
    {
        hexEdit->setText("");
        binEdit->setText("");
    }
}

void ConverterDialog::hexChanged(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok,16);
    if(ok)
    {
        decEdit->setText(QString::number(num));
        binEdit->setText(QString::number(num,2));
    }
    else
    {
        hexEdit->setText("");
        binEdit->setText("");
    }
}

void ConverterDialog::binChanged(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok,2);
    if(ok)
    {
        decEdit->setText(QString::number(num));
        hexEdit->setText(QString::number(num,16));
    }
    else
    {
        hexEdit->setText("");
        binEdit->setText("");
    }
}
