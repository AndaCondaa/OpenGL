#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    Action = 1;

    setWindowTitle("OpenGL Viewing");
    resize(600, 600);
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Widget::resizeGL(int w, int h)
{
//    lastWidth = w;
//    lastHeight = h;
    glViewport(0, 0, w, h);
    if (h == 0) return;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity( );

    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    if (w > h) {
        glOrtho(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0, 1.0, -1.0);
    } else {
        glOrtho(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect, 1.0, -1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Widget::paintGL()
{
//    switch(Action) {
//    case 1:
//         // 전체 창 사용
//         glViewport(0, 0, lastWidth, lastHeight);
//         break;
//    case 2:
//         // 좌하단 사용
//         glViewport(0, 0, lastWidth/2, lastHeight/2);
//         break;
//    case 3:
//         // 우하단 사용
//         glViewport(lastWidth/2, 0, lastWidth/2, lastHeight/2);
//         break;
//    case 4:
//         // 절대 크기 사용
//         glViewport(30, 30, 200, 200);
//         break;
//    }

    glClear(GL_COLOR_BUFFER_BIT);

      glColor3f(0.0, 1.0, 0.0);
      glRectf(-1.0, 1.0, 1.0, -1.0);

//      glBegin(GL_TRIANGLES);
//        glColor3f(1.0, 0.0, 0.0);
//        glVertex2f(0.0, 0.5);
//        glVertex2f(-0.5, -0.5);
//        glVertex2f(0.5, -0.5);
//      glEnd( );
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0, 0.5);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
    glEnd();

    glFlush( );
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    switch(event->key()) {
    case Qt::Key_1:
        Action = 1;
        qDebug() << Action;
        break;
    case Qt::Key_2:
        Action = 2;
        qDebug() << Action;
        break;
    case Qt::Key_3:
        Action = 3;
        qDebug() << Action;
        break;
    case Qt::Key_4:
        Action = 4;
        qDebug() << Action;
        break;
    };

    resize(width(), height());

    update();
}

