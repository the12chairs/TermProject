#ifndef ADDDIALOG_H
#include <QDialog>
#include <QRegExp>
#include <QRegExpValidator>
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
    
public: explicit AddDialog(QWidget *parent = 0);
public: ~AddDialog();

private: void numValidator();
private: Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H