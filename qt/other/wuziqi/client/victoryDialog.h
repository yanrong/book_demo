#ifndef VICTORYDIALOG_HH
#define VICTORYDIALOG_HH

#include <QtGui/QtGui>
#include "ui_victoryDialog.h"

class victoryDialog:public QDialog, public Ui_Dialog
{
    Q_OBJECT

public:
    victoryDialog(QDialog* parent = 0);

signals:
    void quitSignal();

public slots:
    void doQuit();
};

#endif
