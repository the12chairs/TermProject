#ifndef TRAIN_H
#include <QString>
#include <QTime>
#define TRAIN_H

class Train
{
private:
    //Аттрибуты
    int TrainNumber; // Номер поезда
    QString DestinationStation; // Пункт назначения
    QTime DepartureTime; // Время отправления
public:
    //Методы
    Train(); // Конструктор по умолчанию
    Train(int n, QString d, QString t); // Перегруженный конструктор с аттрибутами
    ~Train();// Деструктор

    // Интерфейс класса
    //TODO: Возможно, лишний метод
    int getNumber(); // Для доступа к значению номера поезда

    QString getTrainNumber(); // Для доступа к строковому значению номера поезда
    QString getDestinationStation(); // Для доступа к пункту назначения
    //TODO: Возможно, лишний метод
    QTime getDepartureTime(); // Для доступа к времени отправления, как к классу QTime
    QString getDepartureTime(); // Для доступа к времени отправления

    //-------------

    void setTrainNumber(int n); // Задание номера поезда
    void setDestinationStation(QString d); // Задание станции прибытия
    void setDepartureTime(QTime t); // Задание времени отбытия

};

#endif // TRAIN_H
