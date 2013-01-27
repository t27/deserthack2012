#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    strcpy(dbFile, "database.ktp");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_searchButton_clicked()
{
    QString sub = ui->input->text();
    Record r;
    std::fstream f1;
    f1.open(dbFile, std::ios::in|std::ios::binary);
    int totalCount = 0;
    ui->output->clear();
    f1.read((char*)&r, sizeof(r));
    while(!f1.eof())
    {
        QString super(r.transcript);
        int i = 0;
        int count = 0;
        while ((i = super.indexOf(sub, i) ) != -1)
        {
             if(count==0)
             {
                 ui->output->append("<b>File : " + QString(r.file) + "</b>\n");
                 count++;
             }
             ui->output->append("Found "+sub+" at index position "+QString("%1").arg(i));
             //qDebug() << "Found "<< sub << " at index position" << i;
             ++i;
        }
        if(count!=0)
            totalCount++;
        f1.read((char*)&r, sizeof(r));
    }
    if(totalCount==0)
        ui->output->append("<b>No result found</b>\n");
    f1.close();
}


void MainWindow::on_pushButton_clicked()
{
    QString file = ui->fileName->text();
    std::fstream f1;
    Record r;
    f1.open(dbFile, std::ios::in|std::ios::binary);
    ui->transcript->clear();
    f1.read((char*)&r, sizeof(r));
    while(!f1.eof())
    {
        if(strcmp(r.file, file.toUtf8().data())==0)//match found
        {
            ui->transcript->append(r.transcript);
            return;
        }
        f1.read((char*)&r, sizeof(r));
    }
    ui->transcript->append("File not found");
    return;
}

void MainWindow::on_actionAbout_DBSearch_activated()
{
    QMessageBox msgbox;
    msgbox.about(this,"About DBSearch","<p>Version 1.0</p>\n<p>Made By: Alpha-Phi (TPK)</p>\n<p>An App which searches for text in ktp databases created by SpeechDB</p>");
}
