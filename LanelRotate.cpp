#include "LanelRotate.h"

#include <QPainter>

LabelRotate::LabelRotate(QWidget *parent, const QString & strpath)
    : QLabel{parent},
    m_strPixPath(strpath)
{

}

void LabelRotate::SetRotate(int nRotate)
{
    m_rotate = nRotate;
    update();
}

void LabelRotate::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);

    QTransform transform;
    // 平移
    transform.translate(120, 0);
    // 旋转    X 轴、Y 轴、Z 轴、
    if(m_rotate < 360)
    {
        transform.rotate(m_rotate, Qt::YAxis);
    }
    else if(m_rotate > 360 && m_rotate < 720)
    {
        transform.rotate(m_rotate, Qt::XAxis);
    }
    else
    {
        transform.rotate(m_rotate, Qt::ZAxis);
    }

    painter.setTransform(transform,true);
    painter.drawPixmap(QRect(0, 0, 150, 150), QPixmap(m_strPixPath));
}


