#ifndef BYTECONVERTDIALOG_H
#define BYTECONVERTDIALOG_H

#include <QDialog>
#include <QGridLayout>
#include <QBoxLayout>
#include <QLabel>
#include <QValidator>
#include <QLineEdit>
#include <QPushButton>

class byteConvertDialog : public QDialog
{
    Q_OBJECT
public:
    explicit byteConvertDialog(QWidget *parent = 0);
    
private:
    QLineEdit *decEdit;
    QLineEdit *hexEdit;
    QLineEdit *binEdit;

};

#endif // BYTECONVERTDIALOG_H
