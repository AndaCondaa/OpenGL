#include "panning.h"

#include <QPainter>
#include <QApplication>
#include <QMouseEvent>

Panning::Panning(QWidget *parent)
    : QWidget(parent), _width(350), _height(250), _initial_flag(false), _initial_pos(QPoint())
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    _rect = QRect(QPoint(), QSize(_width, _height));
}

Panning::~Panning()
{
}

void Panning::showEvent(QShowEvent *ev)
{
    if(!_initial_flag)
        _rect.moveCenter(rect().center());
    _initial_flag = true;
    QWidget::showEvent(ev);
}

void Panning::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush( Qt::cyan));
    painter.setPen(Qt::darkCyan);
    painter.drawRect(_rect);
}

void Panning::mousePressEvent(QMouseEvent *ev)
{
    if(_rect.contains(ev->pos())) {
        qApp->setOverrideCursor(QCursor(Qt::OpenHandCursor));
        _initial_pos = ev->pos();
    }
    QWidget::mousePressEvent(ev);
}

void Panning::mouseMoveEvent(QMouseEvent *ev)
{
    if (_rect.contains(ev->pos())) {
        QPoint delta = ev->pos() - _initial_pos;
        _rect.translate(delta);
        update();
        _initial_pos = ev->pos();
    }
    QWidget::mouseMoveEvent(ev);
}

void Panning::mouseReleaseEvent(QMouseEvent *ev)
{
    qApp->restoreOverrideCursor();
    QWidget::mouseReleaseEvent(ev);
}
