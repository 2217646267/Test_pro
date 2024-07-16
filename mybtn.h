#ifndef MYBTN_H
#define MYBTN_H

#include <QPushButton>
#include <QTime>
#include <QTimer>

class MyBtn : public QPushButton
{
    Q_OBJECT
public:
    explicit MyBtn(QWidget *parent = nullptr);

signals:

protected:
    bool event(QEvent* ev)Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent* event)Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent* event)Q_DECL_OVERRIDE;
private:
   QTime m_pressTime;
};

#endif // MYBTN_H
