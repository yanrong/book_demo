#ifndef BYTECONVERTDIALOG_H
#define BYTECONVERTDIALOG_H

#include "QDialog"
#include "ui_byteConvertDialog.h"

class byteConvertDialog:public QDialog
{
    Q_OBJECT
public:
    byteConvertDialog(QDialog *parent=0);

private slots:
    void decChanged(const QString &value);
    void binChanged(const QString &value);
    void hexChanged(const QString &value);

public:
    Ui::byteConvertDialog *ui;

};

#endif
