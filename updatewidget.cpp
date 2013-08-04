#include "updatewidget.h"
#include "ui_updatewidget.h"
#include "widget.h"
#include <QMessageBox>

UpdateWidget::UpdateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UpdateWidget)
{
    ui->setupUi(this);
    //ui->pushButton->setEnabled(false);

    initDisplay();
}

UpdateWidget::~UpdateWidget()
{
    delete ui;
}

void UpdateWidget::initDisplay()
{
    QTimer *timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(updateDisplay()));
    timer->start(1000);
}

void UpdateWidget::on_pushButton_clicked()
{
    Widget *w = new Widget();
    this->hide();
    w->setWindowFlags(Qt::FramelessWindowHint);
    w->show();

}
void UpdateWidget::updateDisplay()
{
    QString str;
    str = getFileContent("../disp/box_status");
    this->ui->label_info->setText(str);
}
QString UpdateWidget::getFileContent(QString filename)
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

void UpdateWidget::on_pushButton_2_clicked()
{
    QMessageBox::about(this,"shit","what");
}
