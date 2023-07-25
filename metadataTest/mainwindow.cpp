#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(450,250);
    connect(ui->loadJsonButton, &QPushButton::clicked, this, &MainWindow::onLoadJsonClicked);
    connect(ui->loadSchemaButton, &QPushButton::clicked, this, &MainWindow::onLoadSchemaClicked);
    connect(ui->validateButton, &QPushButton::clicked, this, &MainWindow::onValidateClicked);
    connect(ui->resetButton,&QPushButton::clicked,this,&MainWindow::resetClicked);
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::white);
    ui->jsonLabel->setAutoFillBackground(true);
    ui-> jsonLabel->setPalette(palette);
    ui->schemaLabel->setAutoFillBackground(true);
    ui->schemaLabel->setPalette(palette);

    jsonDoc = nullptr;
    schemaDoc = nullptr;

    setWindowTitle("JSON Validator");
}

void MainWindow::resetClicked()
{
    ui -> jsonLabel ->setText(" ");
    ui -> schemaLabel ->setText("");
    jsonDoc.reset(nullptr);
    schemaDoc.reset(nullptr);
}
void MainWindow::onLoadJsonClicked()
{
    QString jsonFilePath = QFileDialog::getOpenFileName(this, "Select JSON File");
    if (!jsonFilePath.isEmpty())
    {
        jsonFile.reset(new std::ifstream(jsonFilePath.toStdString()));
        rapidjson::IStreamWrapper jsonStream(*jsonFile);
        jsonDoc.reset(new rapidjson::Document);
        jsonDoc->ParseStream(jsonStream);
        ui -> jsonLabel->setText(" " + jsonFilePath);

        QMessageBox::information(this, "JSON Loaded", "JSON file loaded successfully.");
    }
}

void MainWindow::onLoadSchemaClicked()
{
    QString schemaFilePath = QFileDialog::getOpenFileName(this, "Select JSON Schema File");
    if (!schemaFilePath.isEmpty())
    {
        schemaFile.reset(new std::ifstream(schemaFilePath.toStdString()));
        rapidjson::IStreamWrapper schemaStream(*schemaFile);
        schemaDoc.reset(new rapidjson::Document);
        schemaDoc->ParseStream(schemaStream);
        ui -> schemaLabel->setText(" " + schemaFilePath);
        QMessageBox::information(this, "JSON Schema Loaded", "JSON Schema file loaded successfully.");
    }
}

void MainWindow::onValidateClicked()
{
    if (jsonDoc && schemaDoc)
    {

        // 创建 JSON Schema 解析器
        rapidjson::SchemaDocument schema(*schemaDoc);
        rapidjson::SchemaValidator validator(schema);

        // 验证 JSON 文件
        if (jsonDoc->Accept(validator))
        {
            QMessageBox::information(this, "Validation Result", "JSON data is valid according to the schema.");
        }
        else
        {

            rapidjson::StringBuffer buffer;
            validator.GetInvalidSchemaPointer().StringifyUriFragment(buffer);
            std::string invalidSchema = buffer.GetString();

            validator.GetInvalidDocumentPointer().StringifyUriFragment(buffer);
            std::string invalidDocument = buffer.GetString();

            QString errorMsg = QString("Invalid schema: %1\nInvalid document: %2")
                                   .arg(QString::fromStdString(invalidSchema))
                                   .arg(QString::fromStdString(invalidDocument));          
            QMessageBox::warning(this, "Validation Result", errorMsg);
        }
    }
    else
    {
        QMessageBox::warning(this, "Validation Error", "Please load both JSON file and JSON Schema file.");
    }

}


MainWindow::~MainWindow()
{
    delete ui;
}

