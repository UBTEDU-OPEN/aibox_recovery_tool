#include "tempmask.h"
#include "ui_tempmask.h"
#include <QThread>
#include <QTimer>
#include <QDesktopWidget>

tempmask::tempmask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tempmask)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint| Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint | Qt::ToolTip);
    this->setWindowOpacity(1);
    setAttribute(Qt::WA_TranslucentBackground, true);
//    setAttribute(Qt::WA_StyledBackground);

    this->setFixedSize(QApplication::desktop()->screenGeometry().width(),QApplication::desktop()->screenGeometry().height());
    ui->widget_2->setStyleSheet("background-color:rgba(0,0,0,30)");
    ui->widget_3->setStyleSheet("background:#FFFFFF;border-radius:10px");
    ui->lbsecs->setStyleSheet("font-size: 100px;color: #FC2864;");
    ui->label->setStyleSheet("font-size: 14px;color: #4C545B;line-height: 24px;");
    ui->label_2->setStyleSheet("font-size: 14px;color: #4C545B;line-height: 24px;");

    m_showTimer = new QTimer();
    connect(m_showTimer, &QTimer::timeout, this, &tempmask::doRestore);
    m_showTimer->setSingleShot(false);
    seconds = 2;

    hide();
}

tempmask::~tempmask()
{
    delete ui;
}

void tempmask::showMask()
{
    show();
    m_showTimer->start(1000);

}

void tempmask::doRestore()
{
    if(seconds > 0)
    {
        ui->lbsecs->setText(QString::number(seconds));
        seconds--;
        m_showTimer->start(1000);
    }
    else if(seconds == 0)
    {
        m_showTimer->stop();
        hide();

        QString restore = "/opt/ota_package/ubtech/recovery.sh restore";
        system(restore.toStdString().data());
    }


}

void tempmask::countdown()
{

}
