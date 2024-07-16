#include "rightwidget.h"
#include <QBoxLayout>
#include <QDebug>
#include "mybtn.h"
#include "painterwidget.h"
#include <QMouseEvent>
#include <QApplication>
#include "LanelRotate.h"
#include "IconLabel.h"
#include "BannerWidget.h"
#include "tablemodel.h"
#include "checkboxdelegate.h"
#include <QSlider>
#include <QHeaderView>
#include "HFrameEvent.h"

 RightWidget::RightWidget(QWidget *parent)
    : QWidget{parent}
{
    Init();
}

void RightWidget::Init()
{
    this->setFixedSize(360,600);

    QVBoxLayout* pMainLayout = new QVBoxLayout(this);
    pMainLayout->setContentsMargins(30, 30, 0, 0);

    btn = new MyBtn(this);
    pMainLayout->addWidget(btn);
    btn->installEventFilter(this);

    EventBtn = new QPushButton(this);
    EventBtn->setText("eventbtn");
    EventBtn->installEventFilter(this);

    //原形按钮
    PainterWidget* pEllipsebtn = new PainterWidget(this);
    pEllipsebtn->setFixedSize(50, 50);
    pEllipsebtn->setCheckable(true);

    //滑块
    QSlider *pSlider = new QSlider(this);
    pSlider->setOrientation(Qt::Horizontal);  // 水平方向
    pSlider->setMinimum(0);    // 最小值
    pSlider->setMaximum(360*3);  // 最大值
    pSlider->setSingleStep(1);  // 步长

    //旋转图片 git
    LabelRotate* pLabelRotae = new LabelRotate(this,"://github.png");
    pSlider->setFixedSize(360,35);

    //初始化model和view
    InitDate();

    //彩色标签
    BannerWidget* pBannerWidget = new BannerWidget(this, "hello qt");
    pBannerWidget->setFixedSize(240,60);
    pMainLayout->addWidget(btn);
    pMainLayout->addWidget(pEllipsebtn);
    pMainLayout->addWidget(pSlider);
    pMainLayout->addWidget(pLabelRotae);
    pMainLayout->addWidget(pBannerWidget);
    pMainLayout->addWidget(m_pTableView);
    this->setLayout(pMainLayout);

    connect(pSlider, &QSlider::valueChanged,pLabelRotae, &LabelRotate::SetRotate);
    connect(pEllipsebtn, &QPushButton::clicked, this, [this](bool bShow)
            {
                m_pTableView->setVisible(!bShow);
            });
    connect(EventBtn, &QPushButton::clicked, this, &RightWidget::BtnSlots);

    //蝴蝶图标
    IconLabel* iconLabel = new IconLabel(this, ":/true.png");
    iconLabel->setFixedSize(70,50);
    iconLabel->move(30,500);
}

void RightWidget::BtnSlots()
{
    StructFrame fram;
    fram.width = 200;
    fram.height = 400;
    HFrameEvent My_Event(&fram);
    HFrameEvent::postEvent(btn,&fram);
}

#if 1
bool RightWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == btn) {
        HFrameEvent* FrameEvent = HFrameEvent::event(event);
        if(FrameEvent)
        {
            qDebug() << "eventFilter::My_event";
            return QWidget::eventFilter(obj, event);
            //return true;
        }
    }
    return QWidget::eventFilter(obj, event);

}
#endif


void RightWidget::InitDate()
{
    /*
    QFile qss("/home/liangtuqin/Qt_Project/demo/Demo_1/Myqss.qss");
    if (qss.open(QFile::ReadOnly)){
        qDebug() << qss.readAll();
        qApp->setStyleSheet( qss.readAll());
    }
    */

    m_pTableView = new QTableView(this);
    m_pTableView->setFixedSize(500,400);
    TableModel *pModel = new TableModel(this);
    CheckBoxDelegate *pDelegate = new CheckBoxDelegate(this);

    // 设置单行选中、最后一列拉伸、表头不高亮、无边框等
    m_pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pTableView->horizontalHeader()->setStretchLastSection(true);
    m_pTableView->horizontalHeader()->setHighlightSections(false);
    m_pTableView->verticalHeader()->setVisible(false);
    m_pTableView->setShowGrid(true);
    m_pTableView->setFrameShape(QFrame::NoFrame);
    m_pTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    m_pTableView->setModel(pModel);
    m_pTableView->setItemDelegate(pDelegate);
    m_pTableView->hide();

    // 加载数据、更新界面
    QList<FileRecord> recordList;
    for (int i = 0; i < 6; ++i)
    {
        FileRecord record;
        record.bChecked = false;
        record.strFilePath = QString("E:/Qt/image_%1.png").arg(i + 1);
        recordList.append(record);
    }
    pModel->updateData(recordList);
}
