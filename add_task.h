#ifndef ADD_TASK_H
#define ADD_TASK_H

#include <QDialog>
#include <QDate>
#include <QMessageBox>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class Add_task; }
QT_END_NAMESPACE

class Add_task : public QDialog
{
    Q_OBJECT

public:
    explicit Add_task(QWidget *parent = nullptr);
    ~Add_task();
signals:
    void sendData(QString*);
    void activeButton(bool);

private slots:
    void on_Clear_clicked();
    void on_Add_clicked();
    void on_dateEdit_userDateChanged(const QDate &date);

private:
    Ui::Add_task *ui;
    QString task, desctiption, date;
    void closeEvent(QCloseEvent *);
};

#endif // ADD_TASK_H
