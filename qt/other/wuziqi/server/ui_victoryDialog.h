/********************************************************************************
** Form generated from reading UI file 'victoryDialog.ui'
**
** Created: Wed May 7 14:45:46 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VICTORYDIALOG_H
#define UI_VICTORYDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *congratulationLabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *restartPushButton;
    QPushButton *quitPushButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(350, 106);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 20, 271, 62));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        congratulationLabel = new QLabel(layoutWidget);
        congratulationLabel->setObjectName(QString::fromUtf8("congratulationLabel"));

        verticalLayout->addWidget(congratulationLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        restartPushButton = new QPushButton(layoutWidget);
        restartPushButton->setObjectName(QString::fromUtf8("restartPushButton"));

        horizontalLayout->addWidget(restartPushButton);

        quitPushButton = new QPushButton(layoutWidget);
        quitPushButton->setObjectName(QString::fromUtf8("quitPushButton"));

        horizontalLayout->addWidget(quitPushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        congratulationLabel->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        restartPushButton->setText(QApplication::translate("Dialog", "restart", 0, QApplication::UnicodeUTF8));
        quitPushButton->setText(QApplication::translate("Dialog", "quit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VICTORYDIALOG_H
