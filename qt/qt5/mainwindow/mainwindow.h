#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT
  public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
  
  private:
    void open();
    
    QAction *openAction;
    QMenuBar *menu_bar;
};

#endif //
