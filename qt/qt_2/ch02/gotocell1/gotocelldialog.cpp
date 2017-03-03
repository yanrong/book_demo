#include <QtGui>

#include "gotocelldialog.h"

GoToCellDilaog::GoToCellDilaog(QWidget *parent):QDialog(parent)
{
    setupUi(this);

    QRegExp regExp("[A-Za-z][0-9][1-9]{1,2}");
    lineEdit->setValidator(new QRegExpValidator(regExp,this));

    connect(okButton,SIGNAL(clicked()),this,SLOT(accept()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(reject()));
}

void GoToCellDilaog::on_lineEdit_textChanged()
{
    okButton->setEnabled(lineEdit->hasAcceptableInput());
}
