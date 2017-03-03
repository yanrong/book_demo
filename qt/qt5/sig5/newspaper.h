#include <QObject>

/*
*for qt5 
*/

class Newspaper : public QObject
{
    Q_OBJECT
public:
    Newspaper(const QString &name):m_name(name){}
    void send()
    {
        emit newsPaper(m_name);
    }
signals:
    void newsPaper(const QString &name);

private:
    QString m_name;
};
