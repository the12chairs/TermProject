#ifndef MAINWINDOW_H
#include <QMainWindow>
#include <QVector>
#include "train.h"
#define MAINWINDOW_H


/*
 * Главный виджет приложения. Показывает само расписание.
 */

namespace Ui {
class MainWindow;
class AddDialog;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private: QList<Train> raspis; // Лист расписания

public: explicit MainWindow(QWidget *parent = 0);
public: ~MainWindow();


public: void fillList(QString f, QString s, QString t);
public: void viewRows(Train *train);
private slots:
    void on_AddRaspis_clicked();

    void on_ShowRaspis_clicked();

private: Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
