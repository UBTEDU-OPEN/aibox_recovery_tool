#include "titlebar.h"
#include "ui_titlebar.h"
#include <QPainter>

titlebar::titlebar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::titlebar)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    this->setStyleSheet("background:#E9EEF4;border-top-left-radius:10px;border-top-right-radius:10px");
    ui->icon->setStyleSheet("border-image: url(:/icon/ic_title.png)");
    ui->pbmin->setStyleSheet("background:#A6B8C4;border-radius:12px;border-image: url(:/icon/ic_minimize.svg);");
    ui->pbclose->setStyleSheet("background:#EC7676;border-radius:12px;border-image: url(:/icon/ic_close.svg);");
    connect(ui->pbmin, &QPushButton::clicked, this, &titlebar::onMinClicked);
    connect(ui->pbclose, &QPushButton::clicked, this, &titlebar::onCloseClicked);
}

titlebar::~titlebar()
{
    delete ui;
}

void titlebar::onMinClicked()
{
    emit SigMin();
}

void titlebar::onCloseClicked()
{
    emit SigClose();
}

void titlebar::paintEvent(QPaintEvent *e)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(e);
}
