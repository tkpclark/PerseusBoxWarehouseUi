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

void Updater::run()
{
    QDateTime time;
    QString str;
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
