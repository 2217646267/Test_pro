#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "mybtn.h"
#include <QTableView>

struct FileRecord
{
    bool bChecked;
    QString strFilePath;

};

class RightWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RightWidget(QWidget *parent = nullptr);

public slots:
    void BtnSlots();

protected:
    bool eventFilter(QObject *watched, QEvent *event)override;
private:
    void Init();
    void InitDate();
private:
    QPushButton* EventBtn = nullptr;
    MyBtn* btn = nullptr;
    int eventId = 0;
    QTableView * m_pTableView = nullptr;
};

#endif // RIGHTWIDGET_H
