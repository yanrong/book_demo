#include <QGraphicsScene>
#include <QGraphicsView>

#include <QApplication>

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);

	QGraphicsScene scene;
	scene.addLine(0,0,150,150);

	QGraphicsView view(&scene);
	view.setWindowTitle("Graphics View");
	view.resize(500,500);
	view.show();

	return app.exec();
}

