#include <QObject>
#include <QDebug>

class Reader : public QObject
{
	Q_OBJECT
public:
	Reader(){}
//slots identifier must be constrained by access label,but signal indentitier
//cat be destructed by qt 
public slots:
	void receiveNewspaper(const QString &name)
	{
		qDebug()<<"Receive Newspaper:"<<name;

	}
};
