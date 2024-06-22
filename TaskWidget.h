#pragma once
#include <QtWidgets>
#include <MainWindow.h>
class TaskWidget :
    public QWidget
{
    Q_OBJECT
public:
    TaskWidget(QWidget* parent = nullptr, QString name ="", QString text="", QString date="", QString executor="", QString status = "");
    ~TaskWidget();
    QVBoxLayout* taskLayout;
    QString statusTask;

private:
    MainWindow* parent;
    
    QLabel* nameTaskLbl;
    QLabel* textTaskLbl;
    QLabel* dateTaskLbl;
    QLabel* executorTaskLbl;
};

