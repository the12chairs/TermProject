#ifndef PSEUDODB_H
#include <QString>
#include <QRegExp>
#include <QFile>
#define PSEUDODB_H

/*
 * Класс, реализующий работу с файловой "базой данных"
 */

class PseudoDB
{
private: QFile db;
public: PseudoDB();
public: PseudoDB(QString dbname); // Конструктор
public: ~PseudoDB(); // Деструктор
public: bool createDB(QString dbname); //Создание файла базы данных
public: bool isExists(); // Проверка файла на существование
public: bool readDB(QFile db); // Чтение из файла базы
public: bool writeDB(QFile db); // Запись в базу
public: QString selectDB(QRegExp); //
};

#endif // PSEUDODB_H
