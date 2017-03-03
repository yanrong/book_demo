#include <QtGui>

#include "gotocelldialog.h"

GoToCellDilaog::GoToCellDilaog(QWidget *parent):QDialog(parent)
{
    setupUi(this);
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    QRegExp regExp("[A-Za-z][0-9][1-9]{1,2}");
    lineEdit->setValidator(new QRegExpValidator(regExp,this));

    connect(buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
    connect(buttonBox,SIGNAL(rejected()),this,SLOT(reject()));
}

void GoToCellDilaog::on_lineEdit_textChanged()
{
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(lineEdit->hasAcceptableInput());
}
