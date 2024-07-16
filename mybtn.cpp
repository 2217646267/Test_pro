#include "mybtn.h"
#include <QMouseEvent>
#include <QDebug>
#include "HFrameEvent.h"

MyBtn::MyBtn(QWidget *parent)
    : QPushButton{parent}
{
    setFixedSize(170,50);
    setStyleSheet("background-color: red;");
}
#if 1
bool MyBtn::event(QEvent* ev)
{
    HFrameEvent * event = HFrameEvent::event(ev);
    if (event)
    {
        qDebug() << " QEvent::My_event";
       int nW = event->GetStructframe()->width;
       int nH =   event->GetStructframe()->height;
        this->setText(QString("Width%1,height%2").arg(pos().x()).arg(QString("%1").arg(nW).arg(nH)) );
        return QWidget::event(ev);
        //return true;
    }
    return QWidget::event(ev);
}
#endif

void MyBtn::mousePressEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug() << " mousePressEvent::My_event";
        m_pressTime = QTime::currentTime(); // 记录鼠标按下的时间
    }
}

void MyBtn::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
    {
        int elapsed = m_pressTime.msecsTo(QTime::currentTime()); // 计算鼠标按下到释放的时间差
        if(elapsed >= 500) // 判断时间差是否超过0.5秒
        {
            qDebug() << "Long press";
            this->setText(QString("x%1,y%2").arg(pos().x()).arg(QString("%1").arg(pos().y())) );
        }
        else
        {
            qDebug() << "Click";
            this->setText("");
        }
    }
}

