#include <QTextStream>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include "pseudodb.h"

/*
 * Реализация базы данных. Прототип см. в pseudodb.h
 **/

PseudoDB::PseudoDB()
{
}

PseudoDB::~PseudoDB(){
}

PseudoDB::PseudoDB(QString dbname){
    this->createDB(dbname);
}

QString PseudoDB::getDBName(){
    return this->dbname;
}

bool PseudoDB::createDB(QString dbname){
    this->db.setFileName(dbname);
    this->dbname = dbname;

    if(this->openDB()){
        this->closeDB();
        return 1;
    }
    else
        return 0;
}

void PseudoDB::writeDB(QString text){
    QTextStream out(&this->db);
    out << text;
}

bool PseudoDB::openDB(){
    if(this->db.open(QIODevice::Append | QIODevice::Text | QIODevice::ReadWrite)){
        printf("DB opened");
        colNum();
        return 1;
    }
    else
        return 0;
}

void PseudoDB::closeDB(){
    printf("DB closed");
    this->db.close();
}
int PseudoDB::colNum(){
    QByteArray buf;
    int n=-1;
    do {
        buf = this->db.readLine();
        n++;
    } while (!buf.isEmpty());

}
