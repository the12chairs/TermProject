#ifndef PSEUDODB_H
#include <QString>
#define PSEUDODB_H

/*
 * Класс, реализующий работу с файловой "базой данных"
 */

class PseudoDB
{
public: PseudoDB(); // Конструктор по умолчанию
public: ~PseudoDB(); // Деструктор
public: bool createDB(QString dbname); //Создание файла базы данных
public: bool isExists(QString path);
};

#endif // PSEUDODB_H
