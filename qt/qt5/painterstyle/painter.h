#ifndef PAINTER_H
#define PAINTER_H
#include <QWidget>
#include <QPainter>
#include <QRadialGradient>
#include <QPen>
#include <QVector>
#include <QtGlobal>

class PainterWidget : public QWidget
{
	Q_OBJECT
public:
	PainterWidget(QWidget *parent = 0);
protected:
	void paintEvent(QPaintEvent *);
};

#endif
