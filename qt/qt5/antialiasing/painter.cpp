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

/*	
	painter.drawLine(80,100,650,500);
	painter.setPen(Qt::red);
	painter.drawRect(10,10,100,400);
	*/

	painter.setPen(QPen(Qt::black,5,Qt::DashDotLine,Qt::RoundCap));
	painter.setBrush(Qt::yellow);
	painter.drawEllipse(50,150,200,150);
	
	painter.setRenderHint(QPainter::Antialiasing,true);
	painter.setPen(QPen(Qt::black,5,Qt::DashDotLine,Qt::RoundCap));
	painter.setBrush(Qt::blue);
	painter.drawEllipse(300,150,200,150);
}



