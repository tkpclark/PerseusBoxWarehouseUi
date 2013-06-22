#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QtNetwork>
#include <QTcpSocket>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void initDisplay();
    QString getFileContent(QString);
    void updateNetworkDisplay();
    void updateSDcardDisplay();
    bool isSdcardInserted();
public slots:
    void updateDisplay();

    //void setNetworkFailed();
    //void setNetworkSucceeded();

    
private:
    Ui::Widget *ui;
    QTcpSocket tcpSocket;

};

#endif // WIDGET_H
