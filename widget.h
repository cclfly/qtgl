#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "glwidget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
/*
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w,int h);
    virtual void paintGL();
*/
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
