#include <QMainWindow>
#include <QApplication>

class Layout:public QMainWindow
{
    Q_OBJECT
    public:
        Layout(QWidget *parent=0);
        ~Layout(){}
};

