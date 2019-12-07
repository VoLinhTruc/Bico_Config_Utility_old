#ifndef ESP_WIFI_CONFIG_WINDOW_H
#define ESP_WIFI_CONFIG_WINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

#include "com_port_manager.h"
#include "available_com_port_combobox.h"

#define BC_SWFS_COMMAND "BC_SWFS_COMMAND" // setup wifi station
#define SETTING_WIFI_CONFIG "SETTING_WIFI_CONFIG"

#define BC_SWFS_GET_PROPERTIES "BC_SWFS_GET_PROPERTIES"

#define WIFI_CONNECT "WIFI_CONNECT"
#define WIFI_DISCONNECT "WIFI_DISCONNECT"

#define BC_SWFS_DEVICE_REBOOT "BC_SWFS_DEVICE_REBOOT"



using namespace std;

namespace Ui {
class ESP_Wifi_Config_Window;
}

class ESP_Wifi_Config_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit ESP_Wifi_Config_Window(QWidget *parent = nullptr);
    ~ESP_Wifi_Config_Window();

private slots:
    void on_file_load_pushButton_clicked();

    void on_file_save_pushButton_clicked();

    void on_connect_pushButton_clicked();

    void on_close_pushButton_clicked();

    void on_basic_setting_to_text_clicked();

    void on_text_to_basic_setting_clicked();

    void on_dhcp_enable_checkBox_stateChanged(int arg1);

    void on_ssid_pushButton_clicked();

    void on_password_pushButton_clicked();

    void on_dhcp_enable_pushButton_clicked();

    void on_static_ip_pushButton_clicked();

    void on_gateway_pushButton_clicked();

    void on_subnet_pushButton_clicked();

    void on_submit_all_pushButton_clicked();

    void on_connection_timeout_pushButton_clicked();

    void on_get_properties_pushButton_clicked();

    void on_wifi_connect_pushButton_clicked();

    void on_wifi_disconnect_pushButton_clicked();

    void on_device_reboot_pushButton_clicked();

private:
    Ui::ESP_Wifi_Config_Window *ui;







//Dev's Properties------------------------------------------------------
// Attributes --------------------------
public:

private:
    Com_Port_Manager *com_port_manager;
    Available_Com_Port_ComboBox *bico_port_list_comboBox;
    QTimer *get_serial_data_timer;
    QMetaObject::Connection get_serial_data_timer_connection;
// Attributes --------------------------

// Methods --------------------------
public:

private:
    void devConstruct();
    void devDestroy();
    void JsonObjectToPlaintText(QJsonObject json_object);

public slots:
    void update_serial_data_to_plaint_text();
// Methods --------------------------
//Dev's Properties------------------------------------------------------
};

#endif // ESP_WIFI_CONFIG_WINDOW_H
