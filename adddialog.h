#ifndef ADDDIALOG_H
#include <QDialog>
#include "mainwindow.h"
#define ADDDIALOG_H



/*
 * Диалог для создания экземпляра расписания
 */
namespace Ui {
class AddDialog;
class MainWindow;
}

class AddDialog : public QDialog
{
    Q_OBJECT

private: MainWindow *w;

public: explicit AddDialog(MainWindow *parent = 0);
public: ~AddDialog();
public: void validationSet();
private slots:
    void on_buttonBox_accepted();
    void on_departureTime_textChanged(const QString &arg1);

private: Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
