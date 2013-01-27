#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QDirIterator>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <QMessageBox>
typedef struct{
    char file[50];
    char text[5000];
}record;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString name;
    QDir directory;
    QDir rawdirectory;
    QStringList final;
    QStringList list;
    record finaltranscript;
    QString wavfilename;

public slots:
     void batchConvert();
     void getfiles(QString path);
     QString convertfile(QString fname);
    void convertToFlac();

    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionAbout_SpeechDB_activated();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
