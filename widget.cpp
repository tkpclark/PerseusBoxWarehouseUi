#include "widget.h"
#include "ui_widget.h"
#include "updater.h"
#include <QTimer>
#include <QFile>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    initPicDisplay();


    Updater *updater = new Updater;
    updater->setup_ui(ui);

    updater->start();

}


Widget::~Widget()
{
    delete ui;
}

void Widget::initPicDisplay()
{
    QTimer *timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(updatePicDisplay()));
    timer->start(1000);
}

void Widget::updatePicDisplay()
{
    //ui->label_pic_sd->setStyleSheet("background-image: url(:/pics/home.png);");
    if(this->isSdcardInserted())
    {
        this->ui->label_pic_sd->setStyleSheet("background-image: url(:/pics/sd_in.png);");
    }
    else
    {
        this->ui->label_pic_sd->setStyleSheet("background-image: url(:/pics/sd_out.png);");
    }
}
bool Widget::isSdcardInserted()
{
    QFile f("/dev/sdcard");
    //qDebug() << filename ;
    if(!f.open(QIODevice::ReadOnly ))
    {
        qDebug() << "sdcard doesn't insert!\n";
        return false;
    }
    else
    {
        f.close();
        qDebug() << "sdcard inserted!\n";
        return true;
    }

    //qDebug() << f.readLine() << '\n';

}
