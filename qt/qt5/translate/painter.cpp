#include "painter.h"

PainterWidget::PainterWidget(QWidget *parent):
	QWidget(parent)
{
	resize(800,600);
	setWindowTitle(tr("Paint Demo"));
}

void PainterWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);

	painter.fillRect(10,10,50,100,Qt::red);
	painter.save();
	
	painter.translate(100,0);
	painter.fillRect(10,10,50,100,Qt::yellow);
	painter.restore();
	painter.save();
	
	painter.translate(300,0);
	painter.rotate(30);
	painter.fillRect(10,10,50,100,Qt::green);
	painter.restore();
	painter.save();
	
	painter.translate(400,0);
	painter.scale(2,3);
	painter.fillRect(10,10,50,100,Qt::blue);
	painter.restore();
	painter.save();
	
	painter.translate(600,0);
	painter.shear(0,1);
	painter.fillRect(10,10,50,100,Qt::cyan);
	painter.restore();
}



