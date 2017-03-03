#include "byteConverter.h"

ByteConverter::ByteConverter(QObject *parent):QObject(parent)
{
}


void ByteConverter::setDec(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok);

    if(ok){
        emit hexChanged(QString::number(num,16));
        emit binChanged(QString::number(num,2));
    }else{
        emit hexChanged("");
        emit binChanged("");
    }
}

void ByteConverter::setBin(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok,2);

    if(ok){
        emit hexChanged(QString::number(num,16));
        emit decChanged(QString::number(num));
    }else{
        emit hexChanged("");
        emit decChanged("");
    }
}

void ByteConverter::setHex(const QString &value)
{
    bool ok;
    int num=value.toInt(&ok,16);

    if(ok){
        emit decChanged(QString::number(num));
        emit binChanged(QString::number(num,2));
    }else{
        emit decChanged("");
        emit binChanged("");
    }
}
