#ifndef BYTECONVERTDIALOG_H
#define BYTECONVERTDIALOG_H

#include <QDialog>
#include "ui_byteConvertDialog.h"

class ByteConvertDialog:public QDialog,private Ui::byteConvertDialog
{
    Q_OBJECT
public:
    ByteConvertDialog(QDialog *parent=0);

private slots:
   // void decChanged(const QString &value);
   // void binChanged(const QString &value);
   // void hexChanged(const QString &value);

    void on_decEdit_textChanged(const QString &value);
    void on_binEdit_textChanged(const QString &value);
    void on_hexEdit_textChanged(const QString &value);

};

#endif // BYTECONVERTDIALOG_H
