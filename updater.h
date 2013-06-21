#ifndef UPDATER_H
#define UPDATER_H

#include "widget.h"
#include <QThread>
#include <QLabel>

class Updater : public QThread
{
    Q_OBJECT
public:
    explicit Updater(QObject *parent = 0);
    void setup_ui(Ui::Widget *ui);
    QString getFileContent(QString filename);

signals:
    
public slots:

private:
    Ui::Widget *ui;
protected:
    void run();
};

#endif // UPDATER_H
