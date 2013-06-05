#include "updater.h"
#include "ui_widget.h"
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Updater::Updater(QObject *parent) :
    QThread(parent)
{
}

void Updater::setup_ui(Ui::Widget *ui)
{
    this->ui=ui;
}
QString Updater::getFileContent(QString filename)
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

bool Updater::isSdcardInserted()
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

void Updater::run()
{
    QDateTime time;
    QString str;

    /*
    QString base_dir="/Users/clark/work/ww/perseus/ui_src/pics/";

    this->ui->label_pic_home->setPixmap(QPixmap(base_dir + "home.png"));
    this->ui->label_pic_phone->setPixmap(QPixmap(base_dir + "phone.png"));
    this->ui->label_pic_time->setPixmap(QPixmap(base_dir + "time.png"));

    if(this->isSdcardInserted())
        this->ui->label_pic_sd->setPixmap(QPixmap(base_dir + "sd_in.png"));
    else
        this->ui->label_pic_sd->setPixmap(QPixmap(base_dir + "sd_out.png"));
    */


    this->ui->label_pic_home->setPixmap(QPixmap(":/pics/home.png"));
    this->ui->label_pic_phone->setPixmap(QPixmap(":/pics/phone.png"));
    this->ui->label_pic_time->setPixmap(QPixmap(":/pics/time.png"));

    if(this->isSdcardInserted())
        this->ui->label_pic_sd->setPixmap(QPixmap(":/pics/sd_in.png"));
    else
        this->ui->label_pic_sd->setPixmap(QPixmap(":/pics/sd_out.png"));


    while(1)
    {
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


        sleep(1);
    }
}
