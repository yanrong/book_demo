#include <QMainWindow>

class ButtonWindow:public QMainWindow
{
    Q_OBJECT
    public:
        ButtonWindow(QWidget *parent=0);
         ~ButtonWindow(){}
    private slots:
        void Clicked();
};
