#include <QApplication>
#include "mainwindow.h"
#include <QtSql>


/*
 * Точка входа в приложение. Создает экземпляр главного виджета и показывает его
 */

int main(int argc, char *argv[])
{
    // Подключимся к базе данных
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("myhost");
    db.setDatabaseName("termproject");
    db.setUserName("max");
    db.setPassword("");
    bool ok = db.open();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
