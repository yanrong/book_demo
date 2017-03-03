#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QDialog>
#include <QToolBar>
#include <QAction>
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
	MainWindow(QWidget *parent=0);
	~MainWindow();
	
private:
	QAction *openAction; 

private slots:
	void open();

};

#endif
