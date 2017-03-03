#include "painter.h"

PainterWidget::PainterWidget(QWidget *parent):
	QWidget(parent)
{
	resize(400,300);
	setWindowTitle(tr("Paint Demo"));
}

void PainterWidget::paintEvent(QPaintEvent *)
{
	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing,true);
//	QLinearGradient linearGradient(60,50,200,200);
	/*
	painter.drawLine(80,100,650,500);
	painter.setPen(Qt::red);
	painter.drawRect(10,10,100,400);
	painter.setPen(QPen(Qt::green,5));
	painter.setBrush(Qt::blue);
	*/

	/*****
	linearGradient.setColorAt(0.2,Qt::white);
	linearGradient.setColorAt(0.6,Qt::green);
	linearGradient.setColorAt(1.0,Qt::black);
	painter.setBrush(QBrush(linearGradient));
	painter.drawEllipse(50,50,200,150);*****/
	const int r = 150;
	QConicalGradient conicalGradient(0,0,0);

	conicalGradient.setColorAt(0.0,Qt::red);
	conicalGradient.setColorAt(60.0/360,Qt::yellow);
	conicalGradient.setColorAt(120.0/360,Qt::green);
	conicalGradient.setColorAt(180.0/360.0,Qt::cyan);
	conicalGradient.setColorAt(240.0/360.0,Qt::blue);
	conicalGradient.setColorAt(300.0/360.0,Qt::magenta);
	conicalGradient.setColorAt(1.0,Qt::red);

	painter.translate(r,r);

	QBrush brush(conicalGradient);
	painter.setPen(Qt::NoPen);
	painter.setBrush(brush);
	painter.drawEllipse(QPoint(0,0),r,r);
}

