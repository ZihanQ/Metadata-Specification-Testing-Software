/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *loadJsonButton;
    QPushButton *loadSchemaButton;
    QLabel *jsonLabel;
    QLabel *schemaLabel;
    QPushButton *validateButton;
    QPushButton *resetButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(447, 297);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        loadJsonButton = new QPushButton(centralwidget);
        loadJsonButton->setObjectName(QString::fromUtf8("loadJsonButton"));
        loadJsonButton->setGeometry(QRect(30, 20, 121, 31));
        loadSchemaButton = new QPushButton(centralwidget);
        loadSchemaButton->setObjectName(QString::fromUtf8("loadSchemaButton"));
        loadSchemaButton->setGeometry(QRect(30, 80, 121, 31));
        jsonLabel = new QLabel(centralwidget);
        jsonLabel->setObjectName(QString::fromUtf8("jsonLabel"));
        jsonLabel->setGeometry(QRect(170, 20, 211, 31));
        schemaLabel = new QLabel(centralwidget);
        schemaLabel->setObjectName(QString::fromUtf8("schemaLabel"));
        schemaLabel->setGeometry(QRect(170, 80, 211, 31));
        validateButton = new QPushButton(centralwidget);
        validateButton->setObjectName(QString::fromUtf8("validateButton"));
        validateButton->setGeometry(QRect(70, 160, 91, 31));
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(260, 160, 91, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 447, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        loadJsonButton->setText(QCoreApplication::translate("MainWindow", "Load Json", nullptr));
        loadSchemaButton->setText(QCoreApplication::translate("MainWindow", "Load Json Schema", nullptr));
        jsonLabel->setText(QString());
        schemaLabel->setText(QString());
        validateButton->setText(QCoreApplication::translate("MainWindow", "Validate", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
