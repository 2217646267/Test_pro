#ifndef CHECKBOXDELEGATE_H
#define CHECKBOXDELEGATE_H

#include <QWidget>
#include <QCheckBox>
#include <QApplication>
#include <QStyledItemDelegate>
#include <QMouseEvent>
#include <QPushButton>

class CheckBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CheckBoxDelegate(QObject *parent = nullptr);
private:
    ~CheckBoxDelegate();
protected:
    //绘画 //QStyleOptionViewItem 描述了在一个View控件中绘制对象的所有参数
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //编辑
    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

signals:
};

#endif // CHECKBOXDELEGATE_H
