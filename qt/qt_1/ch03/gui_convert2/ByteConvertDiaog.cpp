#include "ByteConvertDialog.h"

ByteConvertDialog::ByteConvertDialog(QDialog *parent)
    :QDialog(parent)
{
    setupUi(this);

   /* connect(decEdit,SIGNAL(textChanged(const QString&)),this,SLOT(decChanged(const QString&)));
    connect(binEdit,SIGNAL(textChanged(const QString&)),this,SLOT(binChanged(const QString&)));
    connect(hexEdit,SIGNAL(textChanged(const QString&)),this,SLOT(hexChanged(const QString&)));
   */
}

/*
void ByteConvertDialog::decChanged(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok);

    if(ok){
        binEdit->setText(QString::number(num,2));
        hexEdit->setText(QString::number(num,16));
    }else{
        binEdit->setText("");
        hexEdit->setText("");
    }
}

void ByteConvertDialog::binChanged(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok,2);

    if(ok){
        decEdit->setText(QString::number(num));
        hexEdit->setText(QString::number(num,16));
    }else{
        decEdit->setText("");
        hexEdit->setText("");
    }
}

void ByteConvertDialog::hexChanged(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok,16);

    if(ok){
        binEdit->setText(QString::number(num,2));
        decEdit->setText(QString::number(num));
    }else{
        binEdit->setText("");
        decEdit->setText("");
    }
}

*/

void ByteConvertDialog::on_decEdit_textChanged(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok);

    if(ok){
        binEdit->setText(QString::number(num,2));
        hexEdit->setText(QString::number(num,16));
    }else{
        binEdit->setText("");
        hexEdit->setText("");
    }
}

void ByteConvertDialog::on_binEdit_textChanged(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok,2);

    if(ok){
        decEdit->setText(QString::number(num));
        hexEdit->setText(QString::number(num,16));
    }else{
        decEdit->setText("");
        hexEdit->setText("");
    }
}

void ByteConvertDialog::on_hexEdit_textChanged(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok,16);

    if(ok){
        binEdit->setText(QString::number(num,2));
        decEdit->setText(QString::number(num));
    }else{
        binEdit->setText("");
        decEdit->setText("");
    }
}
