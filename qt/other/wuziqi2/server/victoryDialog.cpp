//victoryDialog.cpp

#include <QtGui/QtGui>
#include "victoryDialog.h"

victoryDialog::victoryDialog(QDialog* parent)
    :QDialog(parent)
{
    setupUi(this);

    connect(quitPushButton, SIGNAL(clicked()), this, SLOT(doQuit()));
    connect(restartPushButton, SIGNAL(clicked()), this, SLOT(accept()));
}

void victoryDialog::doQuit(){
    emit quitSignal();
    QDialog::reject();
}
