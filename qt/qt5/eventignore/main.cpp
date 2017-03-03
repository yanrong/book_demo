#include <QApplication>

#include "custombutton.h"

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);

	CustomButton btn;
	btn.setText("This is a button");
	btn.show();

	return app.exec();
}

