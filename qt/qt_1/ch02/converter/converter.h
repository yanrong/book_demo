#ifndef CONVERT_H
#define CONVERT_H

#include <QDialog>

class QLineEdit;

class ConverterDialog:public QDialog
{
    Q_OBJECT
public:
    ConverterDialog();
    ~ConverterDialog(){}

private:
    QLineEdit *decEdit;
    QLineEdit *hexEdit;
    QLineEdit *binEdit;

private slots:
    void decChanged(const QString &);
    void hexChanged(const QString &);
    void binChanged(const QString &);
};

#endif
