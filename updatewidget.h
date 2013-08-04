#ifndef UPDATEWIDGET_H
#define UPDATEWIDGET_H

#include <QWidget>

namespace Ui {
class UpdateWidget;
}

class UpdateWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit UpdateWidget(QWidget *parent = 0);
    ~UpdateWidget();
    void initDisplay();
    QString getFileContent(QString);
    
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

public slots:
    void updateDisplay();

private:
    Ui::UpdateWidget *ui;
};

#endif // UPDATEWIDGET_H
