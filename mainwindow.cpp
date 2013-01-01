#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adddialog.h"
#include "train.h"
#include "searchnum.h"
#include "searchstation.h"
/*
 * Реализация главного виджета. Прототип см. в mainwindow.h, форму - в mainwindow.ui
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_AddRaspis_clicked(){
    // При вызове сигнала будет создан экземпляр
    // дополнительного окна
    AddDialog *ad = new AddDialog(this); // Создадим окно и установим родителем главный виджет
    ad->exec(); // Покажем окно
}


void MainWindow::fillList(QString f, QString s, QString t){

    // Занесение расписания в список
    QTime tmp = QTime::fromString(t,"hh:mm"); // Маска ввода
    Train *train = new Train(f.toInt(), s, tmp); // Создадим указатель на поезд с полученными параметрами
    this->raspis.push_back(*train); // Запихнем его в список
    this->viewRows(train); // Отобразим в таблице
}

void MainWindow::viewRows(Train *train){
    // Вывод расписания на экран
    QTableWidgetItem *first = new QTableWidgetItem; // Создать первый элемент таблицы
    first->setText(train->getTrainNumber()); // Заполним его номером поезда
    QTableWidgetItem *second = new QTableWidgetItem; // Создать второй элемент таблицы
    second->setText(train->getDestinationStation()); // Заполнить его станцией
    QTableWidgetItem *third = new QTableWidgetItem; // Создать третий элемент таблицы
    third->setText(train->getDepartureTime()); // Заполнить его временем отправления
    int row = ui->infoList->rowCount(); // Получим количество имеющихся записей
    ui->infoList->insertRow(row); // Вставим еще одну в конец таблицы
    ui->infoList->setItem(row, 0, first); // Занесем в нее первый
    ui->infoList->setItem(row, 1, second);// второй
    ui->infoList->setItem(row, 2, third);// и третий элементы

}

void MainWindow::clearRows(){
    //Удалим все записи в таблице
    for(int i = ui->infoList->rowCount(); i >= 0; i--)
        ui->infoList->removeRow(i);
}

void MainWindow::on_ShowRaspis_clicked(){
    // Пройдемся по списку и покажем все записи в нем
    // Для начала сотрем все строки, чтобы не записывть в конец
    this->clearRows();
    QList<Train>::iterator i; // Создадим итератор по списку
    // Пройдемся по всему списку
    for (i = raspis.begin(); i != raspis.end(); ++i){
        this->viewRows(&(*i)); // И выведем все записи на экран
    }
}


void MainWindow::searchByNumber(int number){
   QList<Train>::iterator i; // Создадим итератор по списку
   this->clearRows();// Очистим таблицу
   // Пройдемся по списку
   for(i = raspis.begin(); i != raspis.end(); ++i){
       // Указатель на текущий элемент запомним
       Train *tmp = &(*i);
       // Если номер поезда в текущей записи равен искомому -
       if(tmp->getTrainNumber().toInt() == number)
           // Выведем его на экран
           this->viewRows(tmp);
   }
}

void MainWindow::searchByStation(QString station){
    QList<Train>::iterator i; // Создадим итератор по списку
    this->clearRows(); // Очистим таблицу
    // Пройдемся по списку
    for(i = raspis.begin(); i != raspis.end(); ++i){
        Train *tmp = &(*i); // Получим указатель на текущий элемент
        if(tmp->getDestinationStation() == station) // Если его станция равна искомой -
            this->viewRows(tmp); // То выведем запись на экран
    }
}

void MainWindow::on_SearchNum_clicked()
{
    SearchNum *a = new SearchNum(this);
    a->exec();
}

void MainWindow::on_SearchStat_clicked()
{
    SearchStation *a = new SearchStation(this);
    a->exec();
}
