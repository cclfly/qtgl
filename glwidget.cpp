#include "GLWidget.h"
/*
GLWidget::GLWidget(QWidget* parent):QOpenGLWidget(parent)
{
    setGeometry(QRect(140,80,261,191));
    qDebug()<<"创建";
}

GLWidget::GLWidget(int w,int h,QWidget* parent):QOpenGLWidget(parent)
{
    setGeometry(QRect(0,0,w,h));
}

void GLWidget::initializeGL()
{
    qDebug()<<"初始化";
    initializeOpenGLFunctions();
    glClearColor(0.4f,0.8f,1.0f,1.0f);
    qDebug()<<"初始化完成";
}

void GLWidget::resizeGL(int w,int h)
{
    glViewport(0,0,w,h);
}

void GLWidget::paintGL()
{
    qDebug()<<"重绘";
    glClear(GL_COLOR_BUFFER_BIT);

    QOpenGLFunctions *f=QOpenGLContext::currentContext()->functions();
    glLoadIdentity();

    glBegin(GL_TRIANGLES);
    glVertex2f(0,0);
    glVertex2f(100,200);
    glVertex2f(200,100);
    glEnd();
}
*/
