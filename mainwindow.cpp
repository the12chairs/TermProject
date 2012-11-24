#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adddialog.h"
#include "train.h"
#include "pseudodb.h"

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
    QTime tmp = QTime::fromString(t,"hh:mm");
    Train *train = new Train(f.toInt(), s, tmp);
    this->raspis.push_back(*train);
    this->viewRows(train);
}

void MainWindow::viewRows(Train *train){
    // Вывод расписания на экран
    QTableWidgetItem *first = new QTableWidgetItem;
    first->setText(train->getTrainNumber());
    QTableWidgetItem *second = new QTableWidgetItem;
    second->setText(train->getDestinationStation());
    QTableWidgetItem *third = new QTableWidgetItem;
    third->setText(train->getDepartureTime());
    int row = ui->infoList->rowCount();
    ui->infoList->insertRow(row);
    ui->infoList->setItem(row, 0, first);
    ui->infoList->setItem(row, 1, second);
    ui->infoList->setItem(row, 2, third);

}

void MainWindow::on_ShowRaspis_clicked(){

}
