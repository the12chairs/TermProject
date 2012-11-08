#include "adddialog.h"
#include "ui_adddialog.h"
#include "pseudodb.h"
/*
 * Реализация дополнительного окна. Прототип см. addialog.h, форму - в addialog.ui
 */

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    ui->departureTime->setInputMask("00:00"); // Разрешим вводить только нормально заданное время
    ui->trainNumber->setInputMask("999999");  // Шестизначный числовой номер поезда
}

AddDialog::~AddDialog()
{
    delete ui;
}


void AddDialog::on_buttonBox_accepted()
{
    PseudoDB DB("/home/max/qtprojects/TermProject/datebase.txt");
    DB.openDB();
    DB.writeDB(ui->trainNumber->text()+"#"+ui->destinationStation->text()+"#"+ui->departureTime->text()+"\n");
    DB.closeDB();
}

void AddDialog::validationSet(){
    QRegExp exp("[ 0-2][ 0-4]:[ 0-5 ][ 0-9]");
    ui->departureTime->setValidator(new QRegExpValidator(exp, this));
    QRegExp exp1("[ \\d]{6}");
    ui->trainNumber->setValidator(new QRegExpValidator(exp1, this));
}

void AddDialog::on_departureTime_textChanged(const QString &arg1)
{
    this->validationSet();
}
