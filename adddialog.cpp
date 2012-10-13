#include "adddialog.h"
#include "ui_adddialog.h"

/*
 * Реализация дополнительного окна. Прототип см. addialog.h, форму - в addialog.ui
 */

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::numValidator(){
    QRegExp numeric_value("^[0-9]");
    QRegExpValidator *v = new QRegExpValidator(numeric_value, this);
    ui->trainNumber->setValidator(v);
}
