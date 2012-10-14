#include <QTextStream>
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

bool PseudoDB::createDB(QString dbname){
    this->db.setFileName(dbname);
    if(this->db.open(QIODevice::Append | QIODevice::Text)){
        this->db.close();
        return 1;
    }
    else
        return 0;

}

