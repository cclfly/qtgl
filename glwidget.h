#ifndef _GLWIDGET_H_
#define _GLWIDGET_H_

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QDebug>

#include <QtOpenGL/QGLWidget>
#include <QtOpenGL/QGLShader>
#include <QVector>
#include <QVector2D>
#include <QVector4D>
#include <QMatrix4x4>
#include <QTimer>

/*
class GLWidget: public QOpenGLWidget,public QOpenGLFunctions
{
    Q_OBJECT
    public:
    GLWidget(QWidget *parent=0);
    GLWidget(int w,int h,QWidget* parent=0);
    protected:

    virtual void initializeGL();
    virtual void resizeGL(int w,int h);
    virtual void paintGL();


};
*/

class GLWidget:public QOpenGLWidget,public QOpenGLFunctions
{
    Q_OBJECT
    QTimer* timer;
    QVector<QVector2D> vertices;
    QVector<QVector4D> vertex_color;

    QMatrix4x4 m,v,p;

    GLuint m_id,v_id,p_id;

    QGLShaderProgram program;
    public:
    QString gl_version;
    QString log[3];
    GLfloat omega=1.0f;

    GLWidget(QWidget* parent):QOpenGLWidget(parent)
    {
        //setAutoBufferSwap(false);
        timer=new QTimer(this);
        timer->setInterval(16);
        QWidget::connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    }

    void initializeGL()
    {
        vertices<<QVector2D(0,1)<<QVector2D(-1,-1)<<QVector2D(1,-1);
        vertex_color<<QVector4D(1,0,0,1)<<QVector4D(0,1,0,1)<<QVector4D(0,0,1,1);
        initializeOpenGLFunctions();
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        glClearColor(0.4,0.8,1.0,1.0);
        gl_version=QString((const char*)glGetString(GL_VERSION));

        QGLShader* vert=new QGLShader(QGLShader::Vertex,this);
        vert->compileSourceCode(
                              "attribute vec4 v_pos;"
                              "attribute vec4 v_color;"
                              "varying vec4 a_color;"
                              "uniform mat4 m,v,p;"
                              "void main(){"
                              "gl_Position=m*v_pos;"
                              "a_color=v_color;"
                              "}");
           log[0]=vert->log();

          QGLShader* frag=new QGLShader(QGLShader::Fragment,this);
          frag->compileSourceCode(
                              "varying vec4 a_color;"
                              "void main(){"
                              "gl_FragColor=a_color;"
                              "}");
          log[1]=frag->log();

           program.addShader(vert);
           program.addShader(frag);
           program.bindAttributeLocation("v_pos",0);
           program.bindAttributeLocation("v_color",1);
           program.link();
           log[2]=program.log();

           program.setAttributeArray(0,vertices.constData());
           program.setAttributeArray(1,vertex_color.constData());
           program.enableAttributeArray(0);
           program.enableAttributeArray(1);
           program.bind();

//           p.perspective(45.0f,(float)width()/height(),0.1f,100.0f);
//          v.lookAt(QVector3D(0.0,0.0,1.0),QVector3D(0.0,-0.5,0.0),QVector3D(0.0,1.0,0.0));

           m_id=program.uniformLocation("m");
//           v_id=program.uniformLocation("v");
//           p_id=program.uniformLocation("p");

//           program.setUniformValue(v_id,v);
//           program.setUniformValue(p_id,p);
           timer->start();
    }

    void resizeGL(int w, int h)
     {
         glViewport(0, 0, (GLint)w, (GLint)h);
         p.perspective(45.0f,(float)w/h,0.1f,100.0f);
         program.setUniformValue(p_id,p);
     }

    void paintGL()
    {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        m.rotate(omega,QVector3D(0,1,0));
        program.setUniformValue(m_id,m);

        glDrawArrays(GL_TRIANGLES,0,vertices.size());
        //swapBuffers();
    }

    void setOmega(int v)
    {
        omega=v;
    }
};
#endif
