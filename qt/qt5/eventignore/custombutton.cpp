#include "custombutton.h"

//#include <QDebug>

CustomButton::CustomButton(QWidget *parent):
	QPushButton(parent)
{
	connect(this,&CustomButton::clicked,this,&CustomButton::onButtonClicked);
}

void CustomButton::onButtonClicked()
{
	qDebug()<<"you clicked this!\n";
}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
	if(event->button() == Qt::LeftButton){
		qDebug()<<"left";
	}else{
		QPushButton::mousePressEvent(event);
	}
}
