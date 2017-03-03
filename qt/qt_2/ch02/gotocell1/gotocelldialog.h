#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>
#include "ui_gotocelldialog.h"

class GoToCellDilaog:public QDialog, public Ui::GoToCellDialog
{
    Q_OBJECT

public:
    GoToCellDilaog(QWidget *parent=0);

private slots:
    void on_lineEdit_textChanged();
};

#endif
