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


    public: void fillList(QString f, QString s, QString t); // Функция занесения записи в список
    public: void viewRows(Train *train); // Функция вывода определенной записи
    public: void clearRows(); // Очистка таблицы
    public: void searchByNumber(int number); // Поиск по номеру
    public: void searchByStation(QString station); // Поиск по станции
private slots:
    void on_AddRaspis_clicked(); // Слот на клик по кнопке добавления расписания
    void on_ShowRaspis_clicked(); // Слот на клик по кнопке

    void on_SearchNum_clicked(); // Слот на клик по кнопке поиска по номеру поезда

    void on_SearchStat_clicked(); // Слот на клик по кнопке поиска по станции

private: Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
