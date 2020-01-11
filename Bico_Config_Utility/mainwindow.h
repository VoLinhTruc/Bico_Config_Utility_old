#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

#include "esp_wifi_config_window.h"
#include "esp_mqtt_config_window.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ESP_Wifi_Config_Btn_clicked();

private:
    Ui::MainWindow *ui;


//Dev's Properties------------------------------------------------------
// Attributes --------------------------
public:

private:
    ESP_Wifi_Config_Window *_esp_wifi_config_window;
    ESP_MQTT_Config_Window *esp_mqtt_config_window;

// Attributes --------------------------

// Methods --------------------------
public:

private:

private slots:

// Methods --------------------------
//Dev's Properties------------------------------------------------------
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
