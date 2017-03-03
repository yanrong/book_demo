#ifndef PAINTER_H
#define PAINTER_H
#include <QWidget>
#include <QPainter>
#include <QPen>

class PainterWidget : public QWidget
{
	Q_OBJECT
public:
	PainterWidget(QWidget *parent = 0);
protected:
	void paintEvent(QPaintEvent *);
};

#endif
