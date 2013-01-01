#ifndef SEARCHNUM_H
#include <QDialog>
#include "mainwindow.h"
#define SEARCHNUM_H


namespace Ui {
class SearchNum;
}

class SearchNum : public QDialog
{
    Q_OBJECT
    
    private: MainWindow *w; // Родительское окно
    public: explicit SearchNum(MainWindow *parent = 0);
    public: ~SearchNum();
    

private slots:
    void on_buttonBox_accepted(); // Клик по подтверждению

private: Ui::SearchNum *ui;
};

#endif // SEARCHNUM_H
