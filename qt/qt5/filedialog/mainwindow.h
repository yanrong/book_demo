#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

class QTextEdit;

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

protected:
	void closeEvent(QCloseEvent *event);
private slots:
	void openFile();
	void saveFile();
private:
	QAction *openAction;
	QAction *saveAction;

	QTextEdit *textEdit;
};

#endif
