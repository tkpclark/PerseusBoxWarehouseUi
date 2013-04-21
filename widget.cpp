#include "widget.h"
#include "ui_widget.h"
#include "updater.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//update all display on the screen

    Updater *updater = new Updater;
    updater->setup_ui(ui);
    updater->start();

}


Widget::~Widget()
{
    delete ui;
}
