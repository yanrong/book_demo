#include <QApplication>
#include "label.h"

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);

	Label label;
	app.installEventFilter(new EventFilter(&label,&label));
	label.show();

	return app.exec();
}
