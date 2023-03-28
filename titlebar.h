#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>

namespace Ui {
class titlebar;
}

class titlebar : public QWidget
{
    Q_OBJECT

public:
    explicit titlebar(QWidget *parent = 0);
    ~titlebar();

protected:
    void paintEvent(QPaintEvent *);

signals:
    //窗体相关信号发送
    void SigMin();
    void SigClose();

private slots:

    void onMinClicked();
    void onCloseClicked();

private:
    Ui::titlebar *ui;
};



#endif // TITLEBAR_H
