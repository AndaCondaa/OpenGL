#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>

class Widget : public QOpenGLWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // Rect size & pos
    GLfloat rectPosX;
    GLfloat rectPosY;
    GLfloat rectSize;

    // Rect's displacement
    GLfloat xStep;
    GLfloat yStep;

    // Window size
    GLfloat windowWidth;
    GLfloat windowHeight;

private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

public slots:
    void timerFunction();
};
#endif // WIDGET_H
