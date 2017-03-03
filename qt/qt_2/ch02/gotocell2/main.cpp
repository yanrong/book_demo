#include <QApplication>
#include <QDialog>

#include"gotocelldialog.h"

int main(int argc,char *argv[])
{
	QApplication app(argc,argv);
    GoToCellDilaog *dialog=new GoToCellDilaog;
	dialog->show();
	return app.exec();
}
