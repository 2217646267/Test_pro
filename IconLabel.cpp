#include "IconLabel.h"
#include <QPainter>
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>
#define MOUSEPOSDEBUG 0

IconLabel::IconLabel(QWidget *parent, const QString & strpath)
    : QLabel{parent},
    m_strPixPath(strpath)
{
    setMouseTracking(true);
}


void IconLabel::mouseMoveEvent(QMouseEvent *event)
{
    // 鼠标位置 + 扣件间隔 - 扣件宽度一半
    int nx = event->pos().x() + this->geometry().topLeft().x() - (this->width()/2);
    int ny = event->pos().y() + this->geometry().topLeft().y() - (this->height()/2);
    move(nx, ny);
#if MOUSEPOSDEBUG
    qDebug() << "screenPos" <<  event->screenPos();
    qDebug() << "event" <<event->pos();
    qDebug() << "pos" <<pos();
    qDebug() << "topLeft" <<  this->geometry().topLeft();
    qDebug() << nx << ny;
#endif
}


void IconLabel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 绘制图标
    painter.drawPixmap(rect(), QPixmap(m_strPixPath));
    QWidget::paintEvent(event);
}

