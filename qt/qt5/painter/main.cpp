#include "painter.h"
#include <QApplication>

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);

	PainterWidget painter;
	painter.show();

	return app.exec();
}
