/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Sep 23 07:09:04 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout_DBSearch;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *input;
    QPushButton *searchButton;
    QTextEdit *output;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *fileName;
    QPushButton *pushButton;
    QTextEdit *transcript;
    QMenuBar *menuBar;
    QMenu *menuAbout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(526, 509);
        actionAbout_DBSearch = new QAction(MainWindow);
        actionAbout_DBSearch->setObjectName(QString::fromUtf8("actionAbout_DBSearch"));
        actionAbout_DBSearch->setCheckable(false);
        actionAbout_DBSearch->setEnabled(true);
        actionAbout_DBSearch->setIconVisibleInMenu(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        input = new QLineEdit(centralWidget);
        input->setObjectName(QString::fromUtf8("input"));

        horizontalLayout->addWidget(input);

        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        horizontalLayout->addWidget(searchButton);


        verticalLayout->addLayout(horizontalLayout);

        output = new QTextEdit(centralWidget);
        output->setObjectName(QString::fromUtf8("output"));

        verticalLayout->addWidget(output);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        fileName = new QLineEdit(centralWidget);
        fileName->setObjectName(QString::fromUtf8("fileName"));

        horizontalLayout_3->addWidget(fileName);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_3);

        transcript = new QTextEdit(centralWidget);
        transcript->setObjectName(QString::fromUtf8("transcript"));

        verticalLayout->addWidget(transcript);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 526, 25));
        menuBar->setNativeMenuBar(false);
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionAbout_DBSearch);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DBSearch 1.0", 0, QApplication::UnicodeUTF8));
        actionAbout_DBSearch->setText(QApplication::translate("MainWindow", "About DBSearch", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        searchButton->setToolTip(QApplication::translate("MainWindow", "Click to Search", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        searchButton->setText(QApplication::translate("MainWindow", "Search", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        output->setToolTip(QApplication::translate("MainWindow", "Results", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton->setText(QApplication::translate("MainWindow", "Load Transcript", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
