#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QSettings>

namespace Ui {
class dialog;
}

class dialog : public QWidget
{
    Q_OBJECT

public:
    explicit dialog(QWidget *parent = 0);
    ~dialog();

    void showStep1();
    void showStep2();

    Ui::dialog *ui;

signals:
    void showMask();

private slots:
    void onOKClicked();

private:

    QString m_warning;
    int m_step = 1; //表示确认阶段的第1/2个环节
    bool m_save = false;
    QSettings *m_setting;
};

#endif // DIALOG_H
