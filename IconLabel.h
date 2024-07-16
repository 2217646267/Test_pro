#ifndef ICONLABEL_H
#define ICONLABEL_H

#include <QLabel>

class IconLabel : public QLabel
{
    Q_OBJECT
public:
    explicit IconLabel(QWidget *parent = nullptr, const QString & strpath = "");
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
private:
    QString m_strPixPath;
signals:
};

#endif // ICONLABEL_H
