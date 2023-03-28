#include "dialog.h"
#include "ui_dialog.h"
#include <QCheckBox>
#include <pthread.h>
#include <QFile>
#include <iostream>
#include <QThread>
#include <unistd.h>

void* checkPower(void* param);
dialog *g_pDialog = nullptr;

dialog::dialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_StyledBackground);

    this->setGeometry(1,51,618,448);
    this->setStyleSheet("#dialog{background-color:rgba(23,26,45,74%)}");
    ui->widget_5->setStyleSheet("background:#FFFFFF;border-radius:10px;");
    ui->label->setStyleSheet("border-image: url(:/icon/ic_warning_red.png)");
    ui->pbcancel->setStyleSheet("background: #9EB2C0;border-radius: 5px;color:#FFFFFF");
    ui->label_2->setStyleSheet("font-family: PingFangSC-Medium;font-size: 14px;color: #4C545B;line-height: 24px;");
    ui->checkBox->setStyleSheet("QCheckBox{font: 13px;color: #4C545B;line-height: 24px;}"
                                "QCheckBox::indicator {width: 22px;height: 22px;}"
                                "QCheckBox::indicator:unchecked {image: url(:/icon/ic_marquee_unselected.png);}"
                                "QCheckBox::indicator:checked {image: url(:/icon/ic_marquee_selected.png);}");

    connect(ui->pbcancel, &QPushButton::clicked, this, &dialog::close);
    connect(ui->pbok, &QPushButton::clicked, this, &dialog::onOKClicked);
    this->hide();

    m_setting = new QSettings("/home/oneai/userdata/.otaupdate/ota.conf",QSettings::NativeFormat);
    g_pDialog = this;

    pthread_t id_checkPower;
    int ret = pthread_create(&id_checkPower, NULL, checkPower, (void*)this);
    if (ret)
    {
        std::cout << "Create pthread error!" << std::endl;
    }
    else
    {
        pthread_detach(id_checkPower);
    }
}

dialog::~dialog()
{
    delete ui;
}

void dialog::showStep1()
{
    m_step = 1;
    m_warning.clear();
    m_warning.append("<p style='line-height:22px'>");
    m_warning.append(tr("为保证设备安全恢复出厂必须连接电源，恢复过程中请不要关机和断开电源。"));
    ui->label_2->setText(m_warning);
    ui->label_2->setFixedSize(282,120);
    ui->widget_5->setFixedSize(370,200);
    ui->verticalLayout_2->setSpacing(0);
    ui->label_2->setText(m_warning);

    ui->checkBox->hide();
    ui->widget->show();
    show();
}

void dialog::showStep2()
{
    m_step = 2;
    m_warning.clear();
    m_warning.append("<p style='line-height:22px'>");
    m_warning.append(tr("恢复后设备将会失去之前保留在设备上的数据，如果需要保留数据，请备份数据到userdata目录下，并勾选保留userdata选项。"));
    ui->label_2->setText(m_warning);
    ui->label_2->setFixedSize(282,120);
    ui->widget_5->setFixedSize(370,230);
    ui->verticalLayout_2->setSpacing(3);
    ui->widget->hide();
    ui->checkBox->show();
    show();
}

void dialog::onOKClicked()
{
    if(m_step == 1)
    {
        showStep2();
    }
    else if(m_step == 2)
    {
        if(ui->checkBox->isChecked())
        {
            m_setting->setValue("user_data_state", "save");
//            sync();
        }
        else
        {
            m_setting->setValue("user_data_state", "clear");
//            sync();
        }

        emit showMask();

    }
}

void* checkPower(void* param)
{
    std::cout << "CheckPowerThread begin" << std::endl;
    while(true)
    {
        QFile file("/sys/class/power_supply/battery/charger_type");
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
            std::cout << "open fail";
        std::string line = file.readLine().toStdString();
        file.close();
        if(line.find("\n"))
        {
            line = line.substr(0,line.size()-1);
        }
        if(line == "NONE")
        {
            g_pDialog->ui->pbok->setStyleSheet("background: #9EB2C0;border-radius: 5px;color:#FFFFFF");
            g_pDialog->ui->pbok->setEnabled(false);
        }
        else
        {
            g_pDialog->ui->pbok->setStyleSheet("background: #389FF1;border-radius: 5px;color:#FFFFFF");
            g_pDialog->ui->pbok->setEnabled(true);
        }

        QThread::sleep(1);
    }
    std::cout << "DownloadThread end" << std::endl;
    pthread_exit(NULL);
}
