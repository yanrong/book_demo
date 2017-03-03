#include <QApplication>
#include <QLabel>

int main(int argc,char *argv[])
{

	QApplication app(argc,argv);
	QLabel label("<font color=red><h1>this is a <i><b>test program</b></i></h1></font>");
	label.show();
	return app.exec();
}
