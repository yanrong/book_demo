#include "byteconverdialog.h"
#include <QValidator>
#include <QRegExp>
#include <QRegExpValidator>

/*
error: declaration a private memeber in a class ,if it is a pointer and not be initialized
in class definition.it would cause program crushed by referenced a null pointer,the better
solution is create a objection rather a pointer,because a class's objection would initialized
by constructor default.but you can explicted initial it in consrturctor.
*/
byteConvertDialog::byteConvertDialog(QDialog *parent)
    :QDialog(parent)
{
    //init ui pointer ,else it will be segment fault for program
    ui=new Ui::byteConvertDialog;

    ui->setupUi(this);

    connect(ui->decEdit,SIGNAL(textChanged(QString)),this,SLOT(decChanged(QString)));
    connect(ui->binEdit,SIGNAL(textChanged(QString)),this,SLOT(binChanged(QString)));
    connect(ui->hexEdit,SIGNAL(textChanged(QString)),this,SLOT(hexChanged(QString)));

    QIntValidator *decValidator=new QIntValidator(0,256,this);
    ui->decEdit->setValidator(decValidator);

    QRegExpValidator *binValidator=new QRegExpValidator(QRegExp("[0,1]{1,8}"),this);
    ui->binEdit->setValidator(binValidator);

    QRegExpValidator *hexValidator=new QRegExpValidator(QRegExp("[0-9a-fA-F]{1,2}"),this);
    ui->hexEdit->setValidator(hexValidator);
}

void byteConvertDialog::decChanged(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok);

    if(ok){
        ui->binEdit->setText(QString::number(num,2));
        ui->hexEdit->setText(QString::number(num,16));
    }else{
        ui->binEdit->setText("");
        ui->hexEdit->setText("");
    }
}

void byteConvertDialog::binChanged(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok,2);

    if(ok){
        ui->decEdit->setText(QString::number(num));
        ui->hexEdit->setText(QString::number(num,16));
    }else{
        ui->decEdit->setText("");
        ui->hexEdit->setText("");
    }
}

void byteConvertDialog::hexChanged(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok,16);

    if(ok){
        ui->binEdit->setText(QString::number(num,2));
        ui->decEdit->setText(QString::number(num));
    }else{
        ui->binEdit->setText("");
        ui->decEdit->setText("");
    }
}
