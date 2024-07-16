#ifndef LANELROTATE_H
#define LANELROTATE_H

#include <QLabel>
#include <QString>

class LabelRotate : public QLabel
{
    Q_OBJECT
public:
    explicit LabelRotate(QWidget *parent = nullptr, const QString & strpath = "");
public:
    void SetRotate(int nRotate);
protected:
   void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
   QString m_strPixPath;
    int m_rotate = 45;
signals:
};

#endif // LANELROTATE_H
