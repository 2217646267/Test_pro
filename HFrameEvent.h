#ifndef HFRAMEEVENT_H
#define HFRAMEEVENT_H

#include <QEvent>

struct StructFrame
{
    int width;
    int height;
};

class HFrameEvent : public QEvent
{
public:
    explicit HFrameEvent(StructFrame *frame);
public:
    static void postEvent(QObject *obj, StructFrame *frame);
    static HFrameEvent *event(QEvent *e);

public:
    //获取数据
    StructFrame *GetStructframe();

public:
    static int m_eventType;
    StructFrame *m_frame;
signals:
};

#endif // HFRAMEEVENT_H
