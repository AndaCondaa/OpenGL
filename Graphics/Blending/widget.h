#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    GLfloat alpha;
    GLenum src;
    GLenum dest;

protected:
    void keyPressEvent(QKeyEvent* event);

private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
};
#endif // WIDGET_H
