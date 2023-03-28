#ifndef CONTENT_H
#define CONTENT_H

#include <QWidget>

namespace Ui {
class content;
}

class content : public QWidget
{
    Q_OBJECT

public:
    explicit content(QWidget *parent = 0);
    ~content();

protected:
    void paintEvent(QPaintEvent *);

signals:
    void sigStart();

private slots:
    void onStartClicked();

private:
    Ui::content *ui;
};

#endif // CONTENT_H
