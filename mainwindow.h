#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "titlebar.h"
#include "ui_titlebar.h"
#include "content.h"
#include "ui_content.h"
#include "dialog.h"
#include "ui_dialog.h"
#include "tempmask.h"
#include "ui_tempmask.h"

namespace Ui {
class Mainwindow;
}

class Mainwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Mainwindow(QWidget *parent = 0);
    ~Mainwindow();

private slots:
    void showDialog();

private:
    Ui::Mainwindow *ui;
    titlebar *m_titlebar;
    content *m_content;
    dialog *m_dialog;
    tempmask *m_mask;

    bool m_bLeftDown;
    QPoint m_ptPre;//记录前一点，实现窗体移动

protected:

    /**************************************************************************
    * 函数名: mousePressEvent
    * 功能: 鼠标按下事件
    */
    void mousePressEvent(QMouseEvent *e);

    /**************************************************************************
    * 函数名: mouseMoveEvent
    * 功能:鼠标移动事件
    */
    void mouseMoveEvent(QMouseEvent *e);

    /**************************************************************************
    * 函数名: mouseReleaseEvent
    * 功能: 鼠标离开事件
    */
    void mouseReleaseEvent(QMouseEvent *e);
};

#endif // MAINWINDOW_H
