#include "checkboxwidget.h"
#include <QBoxLayout>
#include <QDebug>

CheckboxWidget::CheckboxWidget(QWidget *parent)
    : QWidget{parent}
{
    Init();
    InitConnect();
}

void CheckboxWidget::Init()
{
    this->setFixedSize(240,600);

    m_pPaterBox =  new QCheckBox(this);
    m_pPaterBox->setText(QString::fromLocal8Bit("饮料类型"));

    QCheckBox* pSonBox_1 = new QCheckBox(this);
    pSonBox_1->setText(QString::fromLocal8Bit("可乐"));

    QCheckBox* pSonBox_2 = new QCheckBox(this);
    pSonBox_2->setText(QString::fromLocal8Bit("雪碧"));

    QCheckBox* pSonBox_3 = new QCheckBox(this);
    pSonBox_3->setText(QString::fromLocal8Bit("芬达"));

    QCheckBox* pSonBox_4 = new QCheckBox(this);
    pSonBox_4->setText(QString::fromLocal8Bit("七喜"));

    QVBoxLayout* pMainLayout = new QVBoxLayout(this);
    pMainLayout->setContentsMargins(30, 0, 0, 0);
    pMainLayout->addWidget(m_pPaterBox);
    pMainLayout->addWidget(pSonBox_1);
    pMainLayout->addWidget(pSonBox_2);
    pMainLayout->addWidget(pSonBox_3);
    pMainLayout->addWidget(pSonBox_4);
    this->setLayout(pMainLayout);

    m_CheckboxVct.append(pSonBox_1);
    m_CheckboxVct.append(pSonBox_2);
    m_CheckboxVct.append(pSonBox_3);
    m_CheckboxVct.append(pSonBox_4);

}

void CheckboxWidget::InitConnect()
{
    for(const auto &value : m_CheckboxVct)
    {
        connect(value, &QCheckBox::stateChanged, this, [this, value](int state)
                {
                    qDebug() << value->text();
                    state == Qt::Checked ? m_number++ : m_number--;

                    if (m_number == m_CheckboxVct.size())
                    {
                        m_pPaterBox->setCheckState(Qt::Checked);
                    }
                    else if (m_number == 0)
                    {
                        m_pPaterBox->setCheckState(Qt::Unchecked);
                    }
                    else
                    {
                        m_pPaterBox->setCheckState(Qt::PartiallyChecked);
                    }
                });

        connect(m_pPaterBox, &QCheckBox::clicked, this, [this, value](bool checked)
                {
                    checked == 0 ? value->setCheckState(Qt::Unchecked) : value->setCheckState(Qt::Checked);
                });
    }

}
