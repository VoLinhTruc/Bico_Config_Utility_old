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

void MainWindow::on_ESP_Wifi_Config_Btn_clicked()
{
    _esp_wifi_config_window = new ESP_Wifi_Config_Window();
    _esp_wifi_config_window->show();
}

void MainWindow::on_pushButton_clicked()
{
    esp_mqtt_config_window = new ESP_MQTT_Config_Window();
    esp_mqtt_config_window->show();
}
