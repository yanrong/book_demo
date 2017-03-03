#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
public:
	MainWindow();
protected:
	bool eventFilter(QObject *obj,QEvent *event);

private:
	QTextEdit *textEdit;
};

MainWindow::MainWindow()
{
	textEdit = new QTextEdit;
	setCentralWidget(textEdit);

	textEdit->installEventFilter(this);
}

bool MainWindow::eventFilter(QObject *obj,QEvent *event)
{
	if(obj == textEdit)
	{
		if(event->type() == QEvent::KeyPress)
		{
			QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
			qDebug()<<"ate key press"<<keyEvent->key();
			return true;
		}else{
			return false;
		}
	}else{
		return QMainWindow::eventFilter(obj,event);
	}
}


#endif
