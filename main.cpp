#include <QApplication>
#include "mainwindow.h"


/*
 * Точка входа в приложение. Создает экземпляр главного виджета и показывает его
 */

int main(int argc, char *argv[])
{

    QApplication a(argc, argv); // Создать приложение
    MainWindow w; // Создать главное окно
    w.show(); // Показать главное окно
    
    return a.exec(); // выполнить приложение
}
