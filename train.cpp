#include "train.h"

Train::Train(){ // Конструктор по умолчанию; пуст

}

// Перегруженный конструктор
Train::Train(int n, QString d, QTime t){
    this->TrainNumber = n;
    this->DestinationStation = d;
    this->DepartureTime = t;
}

// Деструктор
Train::~Train(){

}

// Реализация интерфейса
QString Train::getTrainNumber(){
    QString conv = QString::number(this->TrainNumber);
    return conv;
}

QString Train::getDestinationStation(){
    return this->DestinationStation;
}

QString Train::getDepartureTime(){
    this->DepartureTime.toString("hh:mm:ss");
}

void Train::setTrainNumber(QString n){
    this->TrainNumber = n.toInt();
}

void Train::setDestinationStation(QString d){
    this->DestinationStation = d;
}

void Train::setDepartureTime(QString t){
    QTime conv;
    conv.toString(t);
    this->DepartureTime = conv;
}
