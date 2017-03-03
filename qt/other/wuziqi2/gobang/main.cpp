#include <QApplication>
#include "window.h"

int main(int argc, char ** argv)
{
	QApplication app(argc, argv);
    Window game;
    game.show();
	return app.exec();
}
