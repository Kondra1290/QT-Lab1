#ifndef TASK_H
#define TASK_H

#include <QDate>
#include <QString>

class Task
{
public:
    QString taskName, taskDescription;
    QDate date;

    Task(QString, QString, QDate);
    QString getTaskName(){return taskName;}
    QString getTaskDescription(){return taskDescription;}
    QDate getDate(){return date;}
};

#endif // TASK_H
