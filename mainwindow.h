#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <QDataStream>
#include "add_task.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void receiveData(QString*);
    void activeButton(bool);

private slots:
    void on_addTaskButton_clicked();

    void on_deleteTaskButton_clicked();

    void on_detailsTaskButton_clicked();

private:
    QSettings *settings;
    //QSettings settings;
    Ui::MainWindow *ui;
    //Add_task *addTask;
    Add_task addTask;
    void loadSettings();
    void saveSettings();
};
#endif // MAINWINDOW_H
