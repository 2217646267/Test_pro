#include "widget.h"
#include <QApplication>
#include <QDebug>

class WidgtetInface
{
public:
    virtual void test1() = 0;
    virtual void test2() = 0;
};

class basewidget : public WidgtetInface
{
    void test1()
    {

    }
    void test2(){

    }
};

class myWidget : public basewidget
{
    void test1()
    {

    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    new myWidget;
    QString str = "aac";
    if(!str.compare("aac"))
    {
        qDebug() << "-----";
    }
    Widget w;
    w.show();
    return a.exec();
}
