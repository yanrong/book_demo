
#include<QApplication>
#include<QHBoxLayout>
#include<QSlider>
#include<QSpinBox>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QWidget *window=new QWidget;
    window->setWindowTitle("<h1>Enter Your Age</h1>");
    QSpinBox *spinBox=new QSpinBox;
    QSlider *slider=new QSlider(Qt::Horizontal);
    spinBox->setRange(0,130);
    slider->setRange(0,130);
    QObject::connect(spinBox,SIGNAL(valueChange(int)),slider,SLOT(setValue(int)));
    QObject::connect(slider,SIGNAL(valueChange(int)),spinBox,SLOT(setValue(int)));
    spinBox->setValue(35);
    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    window->setLayout(layout);
    window->show();
    return app.exec();
}

