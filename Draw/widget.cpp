#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    resize(600, 600);
}

Widget::~Widget()
{
}

//Draw circle
/*
void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    double rad = 0.5;
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 360; i++){
        double angle, x, y;
        angle = i * 3.141592 / 180;
        x = rad * cos(angle);
        y = rad * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}
*/

//Draw Line
/*
void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    GLfloat w = 1, y;
    for(y=0.8; y>-0.8;y-=0.2){
        glLineWidth(w++);
        glBegin(GL_LINES);
        glVertex2f(-0.8, y);
        glVertex2f(0.8, y);
        glEnd();
    }
    glFlush();
}
*/

//stipple

void Widget::paintGL()
{
    GLushort arPat[] = {0xaaaa, 0xaaaa, 0xaaaa, 0xaaaa,
                       0x33ff, 0x33ff, 0x33ff, 0x57ff, 0x57ff};
    GLint arFac[] = {1, 2, 3, 4, 1, 2, 3, 1, 2};

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glEnable(GL_LINE_STIPPLE);
    GLfloat y;
    GLint idx = 0;
    for(y=0.8; y>-0.8;y-=0.2){
        glLineStipple(arFac[idx], arPat[idx]);
        glBegin(GL_LINES);
        glVertex2f(-0.8, y);
        glVertex2f(0.8, y);
        glEnd();
        idx++;
    };
    glEnd();

    glFlush();
}

