#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <string>
#include <QPalette>
#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/schema.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoadJsonClicked();
    void onLoadSchemaClicked();
    void onValidateClicked();
    void resetClicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<std::ifstream> jsonFile;
    std::unique_ptr<rapidjson::Document> jsonDoc;
    std::unique_ptr<std::ifstream> schemaFile;
    std::unique_ptr<rapidjson::Document> schemaDoc;
    //QPushButton *loadJsonButton;
    //QPushButton *loadSchemaButton;
    //QPushButton *validateButton;
    //QLabel *jsonLabel;
    //QLabel *schemaLabel;
};
#endif // MAINWINDOW_H
