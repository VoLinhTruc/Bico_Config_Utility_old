#ifndef ESP_MQTT_CONFIG_WINDOW_H
#define ESP_MQTT_CONFIG_WINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>

#include "com_port_manager.h"
#include "available_com_port_combobox.h"

#define BC_MQSC_COMMAND "BC_MQSC_COMMAND"
#define SETTING_BROKER_INFO "SETTING_BROKER_INFO"
#define SETTING_CONNECT_PACKAGE "SETTING_CONNECT_PACKAGE"
#define SETTING_SUBSCRIBE_PACKAGE "SETTING_SUBSCRIBE_PACKAGE"
#define SETTING_PUBLISH_PACKAGE "SETTING_PUBLISH_PACKAGE"
#define SETTING_ACTIVITY_CONFIG "SETTING_ACTIVITY_CONFIG"
#define SETTING_PINMODE "SETTING_PINMODE"

namespace Ui {
class ESP_MQTT_Config_Window;
}

class ESP_MQTT_Config_Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit ESP_MQTT_Config_Window(QWidget *parent = nullptr);
    ~ESP_MQTT_Config_Window();

private:
    Ui::ESP_MQTT_Config_Window *ui;



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

public slots:
    void update_serial_data_to_plaint_text();
// Methods --------------------------
//Dev's Properties------------------------------------------------------
private slots:
    void on_connect_pushButton_clicked();
    void on_close_pushButton_clicked();
    void on_file_load_pushButton_clicked();
    void on_file_save_pushButton_clicked();
    void on_submit_all_pushButton_clicked();
    void on_broker_ip_pushButton_clicked();
    void on_broker_port_pushButton_clicked();
    void on_protocol_name_pushButton_clicked();
    void on_protocol_level_pushButton_clicked();
    void on_connect_flag_pushButton_clicked();
    void on_will_topic_pushButton_clicked();
    void on_will_message_pushButton_clicked();
    void on_user_name_pushButton_clicked();
    void on_password_pushButton_clicked();
    void on_topic_filter_pushButton_clicked();
    void on_max_qos_pushButton_clicked();
};
#endif // ESP_MQTT_CONFIG_WINDOW_H
