#include <QApplication>
#include <QDataStream>
#include <QFile>

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);

	QFile file("file.dat");

	file.open(QIODevice::ReadWrite);

	QDataStream out(&file);
	out<<QString("the answer is");
	out<<(qint32)42;

	file.close();
	return app.exec();
}
