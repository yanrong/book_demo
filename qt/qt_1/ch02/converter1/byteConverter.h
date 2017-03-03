#ifndef BYTECONVERTER_H
#define BYTECONVERTER_H

#include <QObject>

class ByteConverter:public QObject
{
    Q_OBJECT
public:
    ByteConverter(QObject *parent=0);

public slots:
    void setDec(const QString&);
    void setBin(const QString&);
    void setHex(const QString&);

signals:
    void binChanged(const QString&);
    void decChanged(const QString&);
    void hexChanged(const QString&);

};

#endif
