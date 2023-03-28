#include "content.h"
#include "ui_content.h"
#include <QPainter>

content::content(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::content)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet("background:#FFFFFF;border-bottom-left-radius:10px;border-bottom-right-radius:10px");
    ui->label->setStyleSheet("font:16px; color:#4C545B");
    ui->label_2->setStyleSheet("font:14px; color:#4C545B");
    ui->label_4->setStyleSheet("font:14px; color:#4C545B;line-height: 30px");
    ui->label_3->setStyleSheet("border-image: url(:/icon/ic_warning_yellow.png);");
    ui->pushButton->setStyleSheet("background: #389FF1;border-radius: 18px;color:#FFFFFF;");

    connect(ui->pushButton, &QPushButton::clicked, this, &content::onStartClicked);
}

content::~content()
{
    delete ui;
}

void content::onStartClicked()
{
    emit sigStart();
}

void content::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}
