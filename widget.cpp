#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //ui->openGLWidget=new GLWidget(0);
    ui->setupUi(this);
    //ui->openGLWidget=new GLWidget;
}

Widget::~Widget()
{
    delete ui;
}
