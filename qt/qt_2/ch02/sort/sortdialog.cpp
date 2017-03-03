#include <QtGui>
#include "sortdialog.h"

SortDialog::SortDialog(QWidget *parent):QDialog(parent)
{
    setupUi(this);

    secondaryGroupBox->hide();
    tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    setColumnRange('A','Z');
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    //clear each combo's text
    primaryColumnCombo->clear();
    secondaryColumnCombo->clear();
    tertiaryColumnCombo->clear();

    //init each combo's text is none,primaryColumnBox has inited
    secondaryColumnCombo->addItem(tr("None"));
    tertiaryColumnCombo->addItem(tr("None"));
    primaryColumnCombo->setMinimumSize(secondaryColumnCombo->sizeHint());

    //add char to echo comboBox
    QChar ch=first;
    while(ch<=last){
        primaryColumnCombo->addItem(QString(ch));
        secondaryColumnCombo->addItem(QString(ch));
        tertiaryColumnCombo->addItem(QString(ch));

        ch=ch.unicode()+1;
    }
}
