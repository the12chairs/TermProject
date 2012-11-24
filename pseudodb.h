#ifndef PSEUDODB_H
#include <QString>
#include <QStringList>
#include <QRegExp>
#include <QFile>
#include "train.h"
#define PSEUDODB_H

/*
 * Класс, реализующий работу с файловой "базой данных"
 */

class PseudoDB
{
private: QFile db;
private: QString dbname;
public: PseudoDB();
public: PseudoDB(QString dbname); // Конструктор
public: ~PseudoDB(); // Деструктор
public: QString getDBName();
public: bool createDB(QString dbname); //Создание файла базы данных
public: bool isExists(); // Проверка файла на существование
public: QString readDB(); // Чтение из файла базы
public: void parseString(QString s, Train *t); // Получает строку, парсит на составляющие и записывает в *t
public: void writeDB(QString text); // Запись в базу
public: QString selectDB(QRegExp where); // Выборка из базы по паттерну
public: bool openDB(); // Открыть базу
public: void closeDB(); // Закрыть базу
public: int colNum();
};

#endif // PSEUDODB_H
