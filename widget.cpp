#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "checkboxwidget.h"
#include "rightwidget.h"
#include <QBoxLayout>
#include <QStackedWidget>
#include <QLabel>
#include <QFont>
#include <QFile>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Init();
}

void Widget::Init()
{
    //标题
    m_pTipLabel = new QLabel(this);
    m_pTipLabel->setFixedSize(180, 50);
    const QString strScrollCation = QString::fromLocal8Bit("青春不老，奋斗不止！");
    m_pTipLabel->setText(strScrollCation);
    m_pTipLabel->setStyleSheet("color:rgb(19, 83, 189);");

    QTimer *pTimer = new QTimer(this);
    connect(pTimer,  &QTimer::timeout,  this, [this,strScrollCation]()
    {
        // 从头开始
        if (m_nPos > strScrollCation.length())
            m_nPos = 0;
        //提取子字符串
        m_pTipLabel->setText(strScrollCation.mid(m_nPos));
        m_nPos++;
        }, Qt::AutoConnection);

    // 定时200毫秒
    pTimer->start(200);

    //图标
    QLabel* pICon = new QLabel(this);
    QString strFilePath = "://github.png";//图标位置自行调整
    QIcon icon = QIcon(strFilePath);
    QPixmap m_pic = icon.pixmap(icon.actualSize(QSize(80, 80)));
    pICon->setPixmap(m_pic);
    pICon->setFixedSize(80,80);
    pICon->move(0,50);

    //主要界面
    CheckboxWidget* pLeftWidget = new CheckboxWidget(this);
    RightWidget* pRightWidget = new RightWidget(this);

    QHBoxLayout* pMainLayout = new QHBoxLayout(this);
    pMainLayout->setContentsMargins(0, 0, 0, 0);
    pMainLayout->addWidget(pLeftWidget);
    pMainLayout->addWidget(pRightWidget);

    this->setLayout(pMainLayout);
}

Widget::~Widget()
{
    delete ui;
}
