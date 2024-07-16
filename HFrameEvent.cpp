#include "HFrameEvent.h"
#include <QApplication>
#include <QDebug>

int HFrameEvent::m_eventType = QEvent::registerEventType(QEvent::User+1);

HFrameEvent::HFrameEvent(StructFrame *frame)
    : QEvent(static_cast<Type>(m_eventType))
{
    m_frame = frame;
}

void HFrameEvent::postEvent(QObject *obj, StructFrame *frame)
{
    if (qApp && obj)
    {
#if 0
    int result = qApp->sendEvent(obj, new HFrameEvent(frame));
    qDebug() << "sendEvent()"<< result;
#else
    qApp->postEvent(obj, new HFrameEvent(frame), Qt::HighEventPriority);
    qDebug() << "postEvent()";
#endif

    }
}

HFrameEvent *HFrameEvent::event(QEvent *e)
{
    return (e && (e->type() == m_eventType)) ? reinterpret_cast<HFrameEvent *>(e) : nullptr;
}

StructFrame *HFrameEvent::GetStructframe()
{
    return m_frame;
}
