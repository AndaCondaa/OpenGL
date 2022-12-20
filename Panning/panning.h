#ifndef PANNING_H
#define PANNING_H

#include <QWidget>

class Panning : public QWidget
{
    Q_OBJECT

public:
    Panning(QWidget *parent = nullptr);
    ~Panning();

protected:
    void showEvent(QShowEvent*) override;
    void paintEvent(QPaintEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

private:
    int _width, _height;
    QRect _rect;
    bool _initial_flag;
    QPoint _initial_pos;
};
#endif // PANNING_H
