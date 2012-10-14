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

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddRaspis_clicked()
{
    // При вызове сигнала будет создан экземпляр
    // дополнительного окна
    AddDialog *ad = new AddDialog(this); // Создадим окно и установим родителем главный виджет
    ad->exec(); // Покажем окно
}

void MainWindow::on_ShowRaspis_clicked()
{
    PseudoDB DB("/home/max/qtprojects/TermProject/datebase.txt");
}
