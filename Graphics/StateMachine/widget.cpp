#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setWindowTitle("State Machine Test");
    resize(600, 600);
}

Widget::~Widget()
{
}

/*
void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.6);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.6, 0.0);
    glVertex2f(-0.4, -0.6);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.4, -0.6);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.6, 0.0);
    glEnd();

    glFlush();
}
*/

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(10.0);
    //glEnable(GL_POINT_SMOOTH);
    //glBegin(GL_POINTS);
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();

    glFlush();
}
