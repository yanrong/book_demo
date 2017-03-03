//finddialog.cpp
#include<QtGui>
#include"finddialog.h"

FindDialog::FindDialog(QWidget *parent):QDialog(parent)
{
    //configuration setting
    label=new QLabel(tr("Find &Waht"));
    lineEdit=new QLineEdit;
    label->setBuddy(lineEdit);

    caseCheckBox=new QCheckBox(tr("Mathc &What"));
    backwardCheckBox=new QCheckBox(tr("Search &backward"));

    findButton=new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton=new QPushButton(tr("Close"));

    //create connection
    connect(lineEdit,SIGNAL(textChange(const QString&)),this,SLOT(enableFindButton(const QString&)));
    connect(findButton,SIGNAL(clicked()),this,SLOT(findClicked()));
    connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));

    //set horizonal box_layout and add in Gui
    QHBoxLayout *topLeftLayout=new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    //set left vertical Box_layout
    QVBoxLayout *leftLayout=new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardCheckBox);

    //set right vetical box_layout
    QVBoxLayout *rightLayout=new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    //set main Layout as horizonal lbox layout
    QHBoxLayout *mainLayout=new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
}

void FindDialog::findClicked()
{
    QString text=lineEdit->text();
    Qt::CaseSensitivity cs=caseCheckBox->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive;
    if(backwardCheckBox->isChecked())
    {
        emit findPrevious(text,cs);
    }else{
        emit findNext(text,cs);
    }
}
void FindDialog::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}
