#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //ui->gridLayoutWidget->setGeometry(0,0,60,80);
    ui->setupUi(this);
    //ui->openGLWidget=new GLWidget;
}

Widget::~Widget()
{
    delete ui;
}