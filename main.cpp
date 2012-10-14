#include <QApplication>
#include "mainwindow.h"

/*
 * Точка входа в приложение. Создает экземпляр главного виджета и показывает его
 */

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
