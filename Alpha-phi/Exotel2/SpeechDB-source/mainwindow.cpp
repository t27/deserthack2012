#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::getfiles(QString path)
{


   // QString path = QFileDialog::getExistingDirectory (this, tr("Directory"), directory.path());
    directory.setPath(path+"/");
//    if(mode==0)//getdb
         list= directory.entryList();
//    else if(mode==1)//getaudio
//         list=rawdirectory.entryList();
    //ui->textEdit->setText(list[2]);


}


void MainWindow::convertToFlac()
{
    name= QFileDialog::getOpenFileName (this,"Browse Files",".",(" Wav File (*.wav)"));
    system(("python soxconvert.py "+name).toUtf8().data());
//    QStringList dirlist=getListOfDirs("./SavedRecordings/");
//    int i;
//    for(i=0;i<dirlist.length();i++)
//    {
    QStringList temp=name.split("/");
    QString tempstr=temp[temp.length()-1];
   QString filnam=(tempstr.split("."))[0];
    getfiles("./SavedRecordings/"+filnam);
    ui->textEdit->append(filnam);
    wavfilename=filnam;
    strcpy(finaltranscript.file,(filnam.toUtf8()).data());
//    }
}



void MainWindow::batchConvert()
{
    QString str1;
    for(int i=2;i<list.length();i++)
    {
       // ui->textEdit->append(directory.canonicalPath()+"/"+list[i]);
        str1=convertfile(directory.canonicalPath()+"/"+list[i]);
        printf("%s",str1.toUtf8().data());
        final.append(str1);
    }
    //write to file here....
    QString resultstr;
    resultstr=final.join(" ");
    ui->textEdit->append(resultstr);
     strcpy(finaltranscript.text,(resultstr.toUtf8()).data());

//    for(int i=0;i<final.length();i++)
//        ui->textEdit->append(final[i]);
}

QString MainWindow::convertfile(QString fname)
{
    QString s="wget -q -U \"Mozilla/5.0\" --post-file=\""+fname+"\" --header=\"Content-Type: audio/x-flac; rate=16000\" -O hello.txt \"http://www.google.com/speech-api/v1/recognize?lang=en-IN&client=chromium\"";
    system((s.toUtf8()).data());
//    QFile textFile("hello.txt");
//    textFile.open(QIODevice::ReadOnly);
    FILE* fp=fopen("hello.txt","r");
    QTextStream textStream(fp);
    //QTextStream textStream()
    QString line;
    line=textStream.readAll();
    line.remove(0,82);
    line.remove(line.indexOf("\""),line.length());
    //ui->textEdit->setText(line);
    //list=line.split("\n");
    return line;
}

void MainWindow::on_pushButton_clicked()
{
    //convertfile();
    batchConvert();
//    std::fstream file1;
//    file1.open("database.ktp", std::ios::out|std::ios::app|std::ios::binary);
//    qDebug(finaltranscript.file);
//    file1.write((char*)&finaltranscript,sizeof(record));
//    file1.close();

    std::ofstream myfile ("database.ktp", std::ios::out | std::ios::app | std::ios::binary);
    myfile.write((char*)&finaltranscript, sizeof(finaltranscript));
    myfile.close();
}


void MainWindow::on_pushButton_2_clicked()
{
//    name= QFileDialog::getOpenFileName (this,"Browse Files",".",(" Flac File (*.flac)"));
//  ui->textEdit->setText(name);
//    if(ui->radioButton->isChecked())
//        getfiles(1);
//    else if(ui->radioButton_2->isChecked())
        convertToFlac();
}

void MainWindow::on_actionAbout_SpeechDB_activated()
{
    QMessageBox msgBox;
    msgBox.about(this,"About SpeechDB","<p>Version 1.0<\p>\n<p>Made By: Alpha-Phi(TPK) </p>\n<p>Converts a WAV file to a .ktp DB which is searchable using the DBSearch app</p>");

}
