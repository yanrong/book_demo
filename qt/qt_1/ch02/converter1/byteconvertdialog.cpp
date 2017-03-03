#ifndef BYTECONVERTERDIALOG_H
#define BYTECONVERTERDIALOG_H

#include "byteconvertdialog.h"
#include "byteConverter.h"

byteConvertDialog::byteConvertDialog(QWidget *parent) :
    QDialog(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QGridLayout* editLayout = new QGridLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;

    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    QLabel* decLabel = new QLabel(tr("Dec"));
    QLabel* hexLabel = new QLabel(tr("Hex"));
    QLabel* binLabel = new QLabel(tr("Bin"));

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

    connect(exitButton,SIGNAL(clicked()),this,SLOT(accept()));

    ByteConverter *bc=new ByteConverter(this);

    connect(decEdit,SIGNAL(textChanged(const QString &)),bc,SLOT(setDec(const QString&)));
    connect(binEdit,SIGNAL(textChanged(const QString &)),bc,SLOT(setBin(const QString&)));
    connect(hexEdit,SIGNAL(textChanged(const QString &)),bc,SLOT(setHex(const QString&)));

    connect(bc,SIGNAL(decChanged(const QString&)),decEdit,SLOT(setText(const QString&)));
    connect(bc,SIGNAL(binChanged(const QString&)),binEdit,SLOT(setText(const QString&)));
    connect(bc,SIGNAL(hexChanged(const QString&)),hexEdit,SLOT(setText(const QString&)));

    resize(230,200);
}

#endif
