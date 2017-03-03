#include <QMainWindow>
#include <QComboBox>

class DuComboBox:public QComboBox
{
    Q_OBJECT
public:
    DuComboBox(QWidget *parent=0);

private slots:
    void Changed(const QString &s);
};
