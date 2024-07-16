#ifndef BANNERWIDGET_H
#define BANNERWIDGET_H

#include <QWidget>
#include <QBasicTimer>
#include <QTimerEvent>

class BannerWidget : public QWidget
{
    Q_OBJECT
public:
    BannerWidget(QWidget *parent = nullptr,const QString &text = "");

protected:
    // 绘制文本
    void paintEvent(QPaintEvent *event);
    // 定时刷新
    void timerEvent(QTimerEvent *event);
private:
    ~BannerWidget();
private:
    QBasicTimer m_timer;
    QString m_strText = "";
    int m_nStep = 0;
};

#endif // BANNERWIDGET_H
