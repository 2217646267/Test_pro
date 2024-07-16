#include "BannerWidget.h"
#include <QPainter>
#include <QDebug>

BannerWidget::BannerWidget(QWidget *parent, const QString &text)
    : QWidget(parent),
    m_strText(text)
{
    setAutoFillBackground(true);

    // 设置文字大小
    QFont newFont = font();
    newFont.setPointSize(newFont.pointSize() + 20);
    setFont(newFont);

    m_timer.start(3000, this);
}

BannerWidget::~BannerWidget()
{
    m_timer.stop();
}

void BannerWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    // 计算文本绘制的起始坐标
    QFontMetrics metrics(font());
    int x = (width() - metrics.width(m_strText)) / 2;
    int y = (height() + metrics.ascent() - metrics.descent()) / 2;

    QColor color;
    QPainter painter(this);
    for (int i = 0; i < m_strText.size(); ++i)
    {
        // 设置色调（H）、饱和度（S）、亮度（V）
        int nIndex = (m_nStep + i) % 16;
       // qDebug() << nIndex << "--" << m_strText[i] <<(15 - nIndex)* 16;
        color.setHsv((15 - nIndex) * 16, 255, 191);
      //   color.setHsv((nIndex) * 16, 255, 191);
        painter.setPen(color);

        // 单个字符绘制
        painter.drawText(x, y, QString(m_strText[i]));

        // 计算下一个字符的x坐标起始点
        x += metrics.width(m_strText[i]);
    }
}

void BannerWidget::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    if (event->timerId() == m_timer.timerId())
    {
        qDebug()<<"m_nStep";
        ++m_nStep;
        update();
    }
    else
    {
        QWidget::timerEvent(event);
    }
}

