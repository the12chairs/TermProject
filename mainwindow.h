#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

#include "train.h"

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

private: QVector<Train> raspis; // Вектор расписания
    

public: explicit MainWindow(QWidget *parent = 0);
public: ~MainWindow();


private slots:
    void on_AddRaspis_clicked();

private: Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
