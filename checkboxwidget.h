#ifndef CHECKBOXWIDGET_H
#define CHECKBOXWIDGET_H

#include <QWidget>
#include <QCheckBox>

class CheckboxWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CheckboxWidget(QWidget *parent = nullptr);

private:
    void Init();
    void InitConnect();

private:
    //子类节点容器
    QVector<QCheckBox*> m_CheckboxVct;
    //父类节点
    QCheckBox* m_pPaterBox = nullptr;
     int m_number = 0;
signals:
};

#endif // CHECKBOXWIDGET_H
