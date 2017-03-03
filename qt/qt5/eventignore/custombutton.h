#ifndef CUSTOMBUTTON_h
#define CUSTOMBUTTON_h

#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>

class CustomButton : public QPushButton
{
	Q_OBJECT
public:
	CustomButton(QWidget *parent = 0);
protected:
	void mousePressEvent(QMouseEvent *event);
private:
	void onButtonClicked();
};

#endif 
