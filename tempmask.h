#ifndef TEMPMASK_H
#define TEMPMASK_H

#include <QWidget>
#include <QTimer>

namespace Ui {
class tempmask;
}

class tempmask : public QWidget
{
    Q_OBJECT

public:
    explicit tempmask(QWidget *parent = 0);
    ~tempmask();

public slots:
    void showMask();

private slots:
    void doRestore();
    void countdown();

private:
    Ui::tempmask *ui;
    QTimer *m_showTimer;
    int seconds;
};

#endif // TEMPMASK_H
