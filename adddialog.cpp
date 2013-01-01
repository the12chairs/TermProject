#include "adddialog.h"
#include "ui_adddialog.h"
/*
 * Реализация дополнительного окна. Прототип см. addialog.h, форму - в addialog.ui
 */

AddDialog::AddDialog(MainWindow *parent) : // В родители пропишем главное окно, иначе до его методов не добраться
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    ui->departureTime->setInputMask("00:00"); // Разрешим вводить только нормально заданное время
    ui->trainNumber->setInputMask("999999");  // Шестизначный числовой номер поезда
    this->w = parent;
}

AddDialog::~AddDialog()
{
    delete ui;
}


void AddDialog::on_buttonBox_accepted()
{
    w->fillList(ui->trainNumber->text(), ui->destinationStation->text(), ui->departureTime->text()); // Занесем значения с формы в список
}

void AddDialog::validationSet(){
    QRegExp exp("(([ 0-1][ 0-9])|(2[ 0-3])):[ 0-5][ 0-9]"); // Валидатор-регулярное выражение
    // Первое число берется из интервала 0-2, если первое число - единица, то второе число вводится
    // из интервала 0-9, если двойка - то из интервала 0-3, второе число вводится из интервала 0-5,
    // четвертое - из интервала 0-9. Т.о., получим маску времени в 24-часовых сутках, от 00:00 до 23:59
    ui->departureTime->setValidator(new QRegExpValidator(exp, this));// Поставим созданный валидатор
    QRegExp exp1("[ \\d]{6}"); // Валидатор-регулярное выражение, можно ввести шестизначное число
    ui->trainNumber->setValidator(new QRegExpValidator(exp1, this)); // Устновим валидатор
}

void AddDialog::on_departureTime_textChanged(const QString &arg1)
{
    this->validationSet(); // При изменении текста вызовем установку валидаторов
}
