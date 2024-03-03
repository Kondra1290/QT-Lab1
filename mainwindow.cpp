#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "add_task.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Персональный органайзер");
    settings = new QSettings("Lab1", "PersonalOrganizer");
    //QCoreApplication::setOrganizationName("Lab1");
    //QCoreApplication::setApplicationName("PersonalOrganizer");
    //addTask=nullptr;
    connect(&addTask, &Add_task::sendData, this, &MainWindow::receiveData); // вот данная строка тебе нужна
    connect(&addTask, &Add_task::activeButton, this, &MainWindow::activeButton);
    loadSettings();
}

void MainWindow::loadSettings()
{
    QStringList strList = settings->allKeys();
    int batchSize = settings->childKeys().size();

    for (int i = 0; i < batchSize; ++i)
        ui->tasksListWidget->addItem(strList[i]);

    ui->tasksListWidget->clearSelection();
}

void MainWindow::on_addTaskButton_clicked()
{
    /*
    addTask = new Add_task();
    connect(addTask, &Add_task::sendData, this, &MainWindow::receiveData);
    connect(addTask, &Add_task::activeButton, this, &MainWindow::activeButton);
    */
    addTask.show();
    ui->addTaskButton->setEnabled(false);
}

void MainWindow::on_deleteTaskButton_clicked()
{
    int index = ui->tasksListWidget->currentRow();
    QListWidgetItem *item = ui->tasksListWidget->currentItem();
    ui->tasksListWidget->removeItemWidget(item);
    settings->remove(item->text());
    delete item;
}

void MainWindow::on_detailsTaskButton_clicked()
{
    QListWidgetItem *i = ui->tasksListWidget->currentItem();
    if(i != nullptr){
        QStringList strList = settings->allKeys();
        int index = ui->tasksListWidget->currentRow();
        QMessageBox msgBox;
        msgBox.setFixedSize(500, 500);
        msgBox.setWindowTitle(i->text());
        //QString key = settings.allKeys()[index];
        QString key = strList[index];
        //msgBox.setText(settings.value(key).value<QVector<QString>>()[2]);
        //msgBox.setInformativeText(settings.value(key).value<QVector<QString>>()[1]);
        QVariantList readList = settings->value(key).toList();
        msgBox.setText(readList.at(2).toString());
        msgBox.setText(readList.at(1).toString());
        msgBox.exec();
    }
    else{
        QMessageBox msgBox;
        msgBox.setFixedSize(500, 500);
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Список пуст");
        msgBox.exec();
    }
}

void MainWindow::receiveData(QString *data) // сюда потом данные приходят
{
    QStringList strList = settings->allKeys();
    if(!strList.contains(data[0]))
    {
        QString key = data[0];
        QVariantList dataList;
        dataList.append(data[0]);
        dataList.append(data[1]);
        dataList.append(data[2]);
        //settings.setValue(key, QVariant::fromValue(data));
        settings->setValue(key, dataList);
        ui->tasksListWidget->addItem(data[0]);
        ui->tasksListWidget->sortItems();
    }
    else{
        QMessageBox msgBox;
        msgBox.setFixedSize(500, 500);
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Задача со схожим названием уже в списке");
        msgBox.exec();
    }
}

void MainWindow::activeButton(bool active)
{
    ui->addTaskButton->setEnabled(true);
}

/*
void MainWindow::saveSettings()
{
    QStringList strList = settings->allKeys();
    for (int i = 0; i < tasks.size(); ++i) {
        if(strList.contains(tasks[i][0])) continue;
        QString key = tasks[i][0];
        settings->setValue(key, QVariant::fromValue(tasks[i]));
    }
}*/

MainWindow::~MainWindow()
{
    //saveSettings();
    //delete settings;
    delete ui;
}
