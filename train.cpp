#include "train.h"



/*
 * Реализация класса расписания. Прототип см. в train.h
 */

Train::Train(){ // Конструктор по умолчанию
    /*
    this->TrainNumber = NULL;
    this->DestinationStation = NULL;
    this->DepartureTime = NULL;
    */
}

// Перегруженный конструктор
Train::Train(int n, QString d, QTime t){
    this->TrainNumber = n;
    this->DestinationStation = d;
    this->DepartureTime = t;
}

// Деструктор
Train::~Train(){
    delete this; // Нужно убирать за собой
}

// Реализация интерфейса
QString Train::getTrainNumber(){
    QString conv = QString::number(this->TrainNumber); // Костыль для конвертации int в QString
    return conv;
}

// Валидаторы на регулярных выражениях

bool Train::isGoodTrainNumber(QString n){

}



//Комментарии излишни
QString Train::getDestinationStation(){
    return this->DestinationStation;
}

QString Train::getDepartureTime(){
    return this->DepartureTime.toString("hh:mm:ss");
}

void Train::setTrainNumber(QString n){
    this->TrainNumber = n.toInt();
}

void Train::setDestinationStation(QString d){
    this->DestinationStation = d;
}

void Train::setDepartureTime(QString t){
    // Конвертируем полученное строковое время в QTime
    QTime conv;
    conv.toString(t);
    this->DepartureTime = conv;
}
