#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QWidget>
#include <QAbstractTableModel>
#include <QList>
#include <QModelIndex>
#include <QAbstractItemModel>
#include <QAbstractListModel>
#include "rightwidget.h"

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TableModel(QObject *parent = nullptr);
    ~TableModel();
public:
     void updateData(QList<FileRecord> recordList);
protected:
    int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value, int role)Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
private:
    QList<FileRecord> m_recordList;
signals:
};

#endif // TABLEMODEL_H
