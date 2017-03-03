#include "mainwindow.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(tr("CuteEdit"));
    resize();

    QLabel *label=new QLabel(tr("Central Label"));
    setCentralWidget(label);
    label->setAlignment(Qt::AlignCenter);
}
