#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QSound"
#include "fstream"
#include "QDebug"
#include "cstring"
#include <QMessageBox>

struct Record
{
    char file[50];
    char transcript[5000];
};

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_searchButton_clicked();


    void on_pushButton_clicked();

    void on_actionAbout_DBSearch_activated();

private:
    Ui::MainWindow *ui;
    char dbFile[50];
};

#endif // MAINWINDOW_H
