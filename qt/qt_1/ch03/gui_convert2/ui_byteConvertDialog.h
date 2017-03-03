/********************************************************************************
** Form generated from reading UI file 'byteConvertDialog.ui'
**
** Created: Mon Jan 6 12:54:50 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BYTECONVERTDIALOG_H
#define UI_BYTECONVERTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_byteConvertDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *decLabel;
    QLineEdit *decEdit;
    QLabel *binLabel;
    QLineEdit *binEdit;
    QLabel *hexLabel;
    QLineEdit *hexEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *quitButton;

    void setupUi(QDialog *byteConvertDialog)
    {
        if (byteConvertDialog->objectName().isEmpty())
            byteConvertDialog->setObjectName(QString::fromUtf8("byteConvertDialog"));
        byteConvertDialog->resize(210, 184);
        verticalLayout = new QVBoxLayout(byteConvertDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        decLabel = new QLabel(byteConvertDialog);
        decLabel->setObjectName(QString::fromUtf8("decLabel"));
        decLabel->setTextFormat(Qt::AutoText);

        gridLayout->addWidget(decLabel, 0, 0, 1, 1);

        decEdit = new QLineEdit(byteConvertDialog);
        decEdit->setObjectName(QString::fromUtf8("decEdit"));

        gridLayout->addWidget(decEdit, 0, 1, 1, 1);

        binLabel = new QLabel(byteConvertDialog);
        binLabel->setObjectName(QString::fromUtf8("binLabel"));

        gridLayout->addWidget(binLabel, 1, 0, 1, 1);

        binEdit = new QLineEdit(byteConvertDialog);
        binEdit->setObjectName(QString::fromUtf8("binEdit"));

        gridLayout->addWidget(binEdit, 1, 1, 1, 1);

        hexLabel = new QLabel(byteConvertDialog);
        hexLabel->setObjectName(QString::fromUtf8("hexLabel"));

        gridLayout->addWidget(hexLabel, 2, 0, 1, 1);

        hexEdit = new QLineEdit(byteConvertDialog);
        hexEdit->setObjectName(QString::fromUtf8("hexEdit"));

        gridLayout->addWidget(hexEdit, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        quitButton = new QPushButton(byteConvertDialog);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout->addWidget(quitButton);


        verticalLayout->addLayout(horizontalLayout);

#ifndef QT_NO_SHORTCUT
        decLabel->setBuddy(decEdit);
        binLabel->setBuddy(binEdit);
        hexLabel->setBuddy(hexEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(decEdit, binEdit);
        QWidget::setTabOrder(binEdit, hexEdit);
        QWidget::setTabOrder(hexEdit, quitButton);

        retranslateUi(byteConvertDialog);
        QObject::connect(quitButton, SIGNAL(clicked()), byteConvertDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(byteConvertDialog);
    } // setupUi

    void retranslateUi(QDialog *byteConvertDialog)
    {
        byteConvertDialog->setWindowTitle(QApplication::translate("byteConvertDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        decLabel->setText(QApplication::translate("byteConvertDialog", "Decimal", 0, QApplication::UnicodeUTF8));
        binLabel->setText(QApplication::translate("byteConvertDialog", "Binary", 0, QApplication::UnicodeUTF8));
        hexLabel->setText(QApplication::translate("byteConvertDialog", "Hex", 0, QApplication::UnicodeUTF8));
        quitButton->setText(QApplication::translate("byteConvertDialog", "Quit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class byteConvertDialog: public Ui_byteConvertDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BYTECONVERTDIALOG_H
