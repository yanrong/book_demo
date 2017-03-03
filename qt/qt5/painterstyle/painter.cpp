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

	QRadialGradient gradient(50,50,50,50,50);
	gradient.setColorAt(0,QColor::fromRgbF(0,1,0,1));
	gradient.setColorAt(1,QColor::fromRgbF(0,0,0,0));
	/*
	painter.drawLine(80,100,650,500);
	painter.setPen(Qt::red);
	painter.drawRect(10,10,100,400);
	painter.setPen(QPen(Qt::green,5));
	*/
	//QPen(Qt::green,3,Qt::DashDotline,Qt::RoundCap,Qt::RoundJoin);
	QVector<qreal> dashs;
	qreal space = 4;
	dashs<<1<<space<<3<<space<<9<<dashs<<27<<space<<9<<space;
	QPen pen;
//	pen.setStyle(Qt::DashDotLine);
	pen.setDashPattern(dashs);
	pen.setWidth(10);
	pen.setBrush(Qt::green);
	pen.setCapStyle(Qt::RoundCap);
	pen.setJoinStyle(Qt::RoundJoin);

	painter.setPen(pen);
	//painter.setBrush(gradient);
	painter.drawEllipse(50,150,400,200);
}



