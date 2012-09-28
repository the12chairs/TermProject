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
    delete[] Train;
}

// Реализация интерфейса
QString Train::getTrainNumber(){

}

QString Train::getDestinationStation()
QString Train::getDepartureTime()
