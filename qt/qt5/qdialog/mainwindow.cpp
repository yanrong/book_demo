#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
	setWindowTitle("Main Window");
    //it will be failed in qrc using alias 
	openAction = new QAction(QIcon(":images/open.png"),tr("&Open..."),this);
	openAction->setShortcuts(QKeySequence::Open);
	openAction->setStatusTip(tr("Open an existing file"));
	connect(openAction,&QAction::triggered,this,&MainWindow::open);

	QMenu *file = menuBar()->addMenu(tr("&File"));
	file->addAction(openAction);

	QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
}

MainWindow::~MainWindow(){}

void MainWindow::open()
{
//if use pointer QDialog *dialog,programming core dump just clicked menu
	QDialog dialog(this);
	dialog.setWindowTitle(tr("Hello,dialog!"));
	dialog.exec();
//	qDebug()<<dialog.reslut();
}
