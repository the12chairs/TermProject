#include "searchnum.h"
#include "ui_searchnum.h"

SearchNum::SearchNum(MainWindow *parent) :
    QDialog(parent),
    ui(new Ui::SearchNum)
{
    ui->setupUi(this);
    ui->numberBox->setInputMask("999999");// Установим маску ввода
    this->w = parent;
}

SearchNum::~SearchNum()
{
    delete ui;
}

void SearchNum::on_buttonBox_accepted()
{
    w->searchByNumber(this->ui->numberBox->text().toInt()); // Найдем запись по введенному номеру
}
