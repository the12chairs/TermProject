#ifndef SEARCHSTATION_H
#include <QDialog>
#include "mainwindow.h"
#define SEARCHSTATION_H

namespace Ui {
    class SearchStation;
}

class SearchStation : public QDialog
{
    Q_OBJECT
    private: MainWindow* w; // Родительское окно

    public: explicit SearchStation(MainWindow *parent = 0); // Родитель
    public: ~SearchStation();
    
private slots:
    void on_buttonBox_accepted(); // Клик по подтверждению

private: Ui::SearchStation *ui;
};

#endif // SEARCHSTATION_H
