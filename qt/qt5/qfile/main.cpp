#include <QApplication>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
///#include <QIODevice>

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);

	QFile file("in.txt");

	if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
		qDebug()<<"Open File failed";
		return -1;
	}else{
		while(!file.atEnd())
			qDebug()<<file.readLine();
	}

	QFileInfo info(file);
	qDebug()<<info.isDir();
	qDebug()<<info.isExecutable();
	qDebug()<<info.baseName();
	qDebug()<<info.completeBaseName();
	qDebug()<<info.suffix();
	qDebug()<<info.completeSuffix();

	return app.exec();
}

