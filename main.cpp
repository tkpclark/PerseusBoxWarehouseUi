#include "widget.h"
#include <QApplication>
#include <QTextCodec>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QTextCodec *codec = QTextCodec::codecForName("GB2312");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();
    
    return a.exec();
}
