#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));
    
    openAction = new QAction(QIcon(":/images/open.png"),tr("&Open"),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("open an exiting file"));
    //using qt5 connect function
    connect(openAction,&QAction::triggered,this,&MainWindow::open);
    menu_bar = new QMenuBar(this);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    menu_bar->addMenu(file);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    QToolBar *toolBar_th = addToolBar(tr("&Edit"));
    toolBar_th->addAction(openAction);
    //errro whie using  statusBar() directly,must use this pointer to reference it
    QStatusBar *statusBar = this->statusBar();
    statusBar->addAction(openAction);
} 

MainWindow::~MainWindow(){}

void MainWindow::open()
{
    QMessageBox::information(this,tr("Information"),tr("Open"));
}
