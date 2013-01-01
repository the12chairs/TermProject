#include "searchstation.h"
#include "ui_searchstation.h"
#include "mainwindow.h"
SearchStation::SearchStation(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::SearchStation)
{
    ui->setupUi(this);
    this->w = parent;
}

SearchStation::~SearchStation()
{
    delete ui;
}

void SearchStation::on_buttonBox_accepted()
{
    w->searchByStation(this->ui->stationBox->text()); // Найдем записи по введенной станции
}
