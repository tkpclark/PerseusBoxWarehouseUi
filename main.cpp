#include "updatewidget.h"
#include <QApplication>
#include <QTextCodec>
#include <QResource>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    QTextCodec *codec = QTextCodec::codecForName("GB2312");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

   // QResource::registerResource("/Users/clark/work/ww/perseus/ui_src/pics/pics.qrc");
    QResource::registerResource("../pics/pics.qrc");

    /*
    Widget w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();
    */

    UpdateWidget uw;
    uw.setWindowFlags(Qt::FramelessWindowHint);
    uw.show();

    return a.exec();
}
