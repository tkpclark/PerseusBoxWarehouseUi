#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <QString>
#include <QtNetwork>
#include <QTcpSocket>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    connect(&tcpSocket,SIGNAL(connected()),this,SLOT(setNetworkSucceeded()) );
 //   connect(&tcpSocket,SIGNAL(error()),this,SLOT(setNetworkFailed()));
//connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    initDisplay();

}


Widget::~Widget()
{
    delete ui;
}

void Widget::initDisplay()
{
    QTimer *timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(updateDisplay()));
    timer->start(1000);
}
/*
void Widget::setNetworkSucceeded()
{
    qDebug() << "set network succeed!";
    this->ui->label_network->setStyleSheet("background-image: url(:/pics/inter_on.png);");
    tcpSocket.close();
}

void Widget::setNetworkFailed()
{
    qDebug() << "set network failed!";
    this->ui->label_network->setStyleSheet("background-image: url(:/pics/inter_off.png);");
    tcpSocket.close();
}
*/
void Widget::updateNetworkDisplay()
{

    //qDebug() << "trying network...";
    tcpSocket.connectToHost("202.85.215.135", 21);
    if(tcpSocket.waitForConnected(300))
    {
        qDebug() << "set network ok";
        this->ui->label_network->setStyleSheet("background-image: url(:/pics/inter_on.png);");
    }
    else
    {
        qDebug() << "set network failed";
        this->ui->label_network->setStyleSheet("background-image: url(:/pics/inter_off.png);");
    }
    tcpSocket.close();
}

void Widget::updateSDcardDisplay()
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

void Widget::updateDisplay()
{

    updateSDcardDisplay();
    updateNetworkDisplay();

    QDateTime time;
    QString str;

    //time
    time = QDateTime::currentDateTime();
    str = time.toString("hh:mm:ss");
    this->ui->label_time->setText(str);

    //date
    str = time.toString("yyyy/MM/dd");
    this->ui->label_date->setText(str);


    //str = getFileContent("/Users/clark/work/ww/perseus/ui_src/disp/ip");
    //qDebug() << str << '\n';


    str = getFileContent("../disp/ip");
    this->ui->label_ip->setText(str);

    str = getFileContent("../disp/mac");
    this->ui->label_mac->setText(str);

    str = getFileContent("../disp/vai");
    this->ui->label_vai->setText("AI:"+str);

    str = getFileContent("../disp/vud");
    this->ui->label_vud->setText("UD:"+str);

    str = getFileContent("../disp/vul");
    this->ui->label_vul->setText("UL:"+str);

    str = getFileContent("../disp/box_id");
    this->ui->label_boxid->setText(str);

    str = getFileContent("../disp/upload");
    this->ui->label_ftp->setText(str);

    str = getFileContent("../disp/install_seq");
    this->ui->label_installnum->setText(str);

    str = getFileContent("../disp/box_status");
    //str = getFileContent("/Users/clark/tmp/box_status");
    this->ui->label_info->setText(str);

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

QString Widget::getFileContent(QString filename)
{

    QFile f(filename);
    //qDebug() << filename ;
    if(!f.open(QIODevice::ReadOnly ))
    {
        qDebug() << "failed to open" << filename << '\n';
        return NULL;
    }
    QString data = f.readAll();

    //qDebug() << f.readLine() << '\n';
    f.close();

    return data;
}
