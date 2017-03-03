#include <qmainwindow.h>
#include <qlineedit.h>

class myLineEdit:public QMainWindow
{
    Q_OBJECT
    public:
        myLineEdit(QWidget *parent=0);
        QLineEdit *password;
        QLineEdit *username;

    private slots:
        void Click();
};
