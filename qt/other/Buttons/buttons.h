#include <QMainWindow>
#include <QCheckBox>
#include <QRadioButton>
#include <QAbstractButton>

class Buttons:public QMainWindow
{
    Q_OBJECT
public:
    Buttons(QWidget *parent=0);

private:
    void printActive(QAbstractButton *button);
    QCheckBox *checkbox;
    QRadioButton * radiobutton1,*radiobutton2;

private slots:
    void Click();
};
