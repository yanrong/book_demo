#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QtGui/QtGui>

class StartDialog:public QDialog
{
    Q_OBJECT

public:
    QLabel* hostLabel;
    QLabel* portLabel;
    QLineEdit* hostLineEdit;
    QLineEdit* portLineEdit;
    QLabel* statusLabel;
    QPushButton* startButton;
    QDialogButtonBox* buttonBox;
    QPushButton* quitButton;

    StartDialog(QWidget* parent = 0);

public slots:
    void doStart();
    void enableStartButton();
    void doQuit();

signals:
    void start(const QString&, const QString&);
    void quitClient();
};

#endif // STARTDIALOG_H
