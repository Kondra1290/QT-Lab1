#include "add_task.h"
#include "./ui_add_task.h"

Add_task::Add_task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_task)
{
    ui->setupUi(this);
    this->setWindowTitle("Добавление новой задачи");
    ui->dateEdit->setDate(QDate::currentDate());
}

void Add_task::on_dateEdit_userDateChanged(const QDate &date)
{
    ui->dateEdit->setMinimumDate(QDate::currentDate());
}

void Add_task::on_Add_clicked()
{
    /*
    task = ui->lineEdit->text().simplified();
    desctiption = ui->textEdit->toPlainText().simplified();
    //QDateTimes dateTime = QDateTime::currentDateTime();
    //QDate curDate = dateTime.
    if(!task.isEmpty() && !desctiption.isEmpty())
    {
        date = ui->dateEdit->date().toString().simplified();
        emit sendData(QVector<QString>{task, desctiption, date});
    }
    else{
        QMessageBox msgBox;
        msgBox.setFixedSize(500, 500);
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Не коректные данные");
        //msgBox.setInformativeText(tasks[index][1]);
        msgBox.exec();
    }
    */
}


void Add_task::on_Clear_clicked()
{
    ui->lineEdit->clear();
    ui->textEdit->clear();
}

void Add_task::closeEvent(QCloseEvent *event)
{
    task = ui->lineEdit->text().simplified();
    desctiption = ui->textEdit->toPlainText().simplified();
    if(!task.isEmpty() && !desctiption.isEmpty())
    {
        date = ui->dateEdit->date().toString();
        QString arr[3]{task, desctiption, date};
        emit sendData(arr); // sendData который я прописывал в конструкторе Mainvindow
    }
    else{
        QMessageBox msgBox;
        msgBox.setFixedSize(500, 500);
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Некоректные данные");
        msgBox.exec();
    }

    ui->lineEdit->clear();
    ui->textEdit->clear();
    emit activeButton(true);
    QDialog::closeEvent(event);
    //deleteLater();
}

Add_task::~Add_task()
{
    delete ui;
}

