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
    Train(int n, QString d, QTime t); // Перегруженный конструктор с аттрибутами
    ~Train();// Деструктор

    // Интерфейс класса
    //TODO: Возможно, лишний метод
    QString getTrainNumber(); // Для доступа к строковому значению номера поезда
    QString getDestinationStation(); // Для доступа к пункту назначения
    QString getDepartureTime(); // Для доступа к времени отправления

    // Общедоступные слоты для вывода результатов в форму (возможно, лишнее)
public slots:
    void setTrainNumber(QString n); // Задание номера поезда
    void setDestinationStation(QString d); // Задание станции прибытия
    void setDepartureTime(QString t); // Задание времени отбытия

};

#endif // TRAIN_H
