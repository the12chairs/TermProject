#ifndef TRAIN_H
#include <QString>
#include <QTime>
#define TRAIN_H


/*
 * Класс расписания. Содержит номер поезда, конечную станцию и время отправления.
 * Также имеет интерфейс для работы с атрибутами и интерфейс слотов для общения с формой.
 */

class Train
{
    //Атрибуты
    private: int TrainNumber; // Номер поезда
    private: QString DestinationStation; // Пункт назначения
    private: QTime DepartureTime; // Время отправления
    //Методы
    public: Train(); // Конструктор по умолчанию
    public: Train(int n, QString d, QTime t); // Перегруженный конструктор с атрибутами
    public: ~Train();// Деструктор

    // Интерфейс класса
    public: QString getTrainNumber(); // Для доступа к строковому значению номера поезда
    public: QString getDestinationStation(); // Для доступа к пункту назначения
    public: QString getDepartureTime(); // Для доступа к времени отправления


    public: void setTrainNumber(QString n); // Задание номера поезда
    public: void setDestinationStation(QString d); // Задание станции прибытия
    public: void setDepartureTime(QString t); // Задание времени отбытия

};

#endif // TRAIN_H
