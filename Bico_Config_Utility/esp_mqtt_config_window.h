#ifndef ESP_MQTT_CONFIG_WINDOW_H
#define ESP_MQTT_CONFIG_WINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

#include "com_port_manager.h"
#include "available_com_port_combobox.h"

#define BC_MQSC_COMMAND "BC_MQSC_COMMAND"
#define BC_MQSC_COMMAND_SEPERATOR "-----BC_MQSC_COMMAND_SEPERATOR-----"
#define SETTING_BROKER_INFO "SETTING_BROKER_INFO"
#define SETTING_CONNECT_PACKAGE "SETTING_CONNECT_PACKAGE"
#define SETTING_SUBSCRIBE_PACKAGE "SETTING_SUBSCRIBE_PACKAGE"
#define SETTING_PUBLISH_PACKAGE "SETTING_PUBLISH_PACKAGE"
#define SETTING_ACTIVITY_CONFIG "SETTING_ACTIVITY_CONFIG"
#define SETTING_PINMODE "SETTING_PINMODE"

typedef enum
{
    CONTINUOUS = 1,
    TRIGGER = 2
}MQTT_Publish_Mode;

typedef enum
{
    RISING_AND_FALLING_TRIGGER = 1,
    RISING_TRIGGER = 2,
    FALLING_TRIGGER = 3,
    // UART_TRIGGER = 4 // this trigger type is more stable than RISING_TRIGGER or FALLING_TRIGGER
}MQTT_Publish_Trigger_type;


using namespace std;

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

    void JsonObjectToPlaintText(QJsonObject json_object);

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
    void on_broker_info_setting_to_text_clicked();
    void on_connect_packet_setting_to_text_clicked();
    void on_subscribe_packet_setting_to_text_3_clicked();
    void on_start_up_general_setting_checkBox_stateChanged(int arg1);
    void on_keep_alive_pushButton_clicked();
    void on_client_identifier_pushButton_clicked();
    void on_password_flag_checkBox_stateChanged(int arg1);
    void on_user_flag_checkBox_stateChanged(int arg1);
    void on_will_flag_checkBox_stateChanged(int arg1);
    void on_setting_to_text_clicked();
    void on_text_to_setting_clicked();
    void on_publish_general_setting_checkBox_stateChanged(int arg1);
    void on_publish_flag_pushButton_clicked();
    void on_topic_name_pushButton_clicked();
    void on_application_message_pushButton_clicked();
    void on_push_mode_pushButton_clicked();
    void on_continous_interval_pushButton_clicked();
    void on_trigger_type_pushButton_clicked();
    void on_trigger_pin_pushButton_clicked();
    void on_uart_trigger_sign_pushButton_clicked();
    void on_publish_packet_setting_to_text_clicked();
    void on_activity_config_setting_to_text_clicked();
    void on_publish_mode_comboBox_currentTextChanged(const QString &arg1);
    void on_trigger_type_comboBox_currentTextChanged(const QString &arg1);
    void on_pin_16_pushButton_clicked();
    void on_pin_5_pushButton_clicked();
    void on_pin_4_pushButton_clicked();
    void on_pin_0_pushButton_clicked();
    void on_pin_2_pushButton_clicked();
    void on_pin_14_pushButton_clicked();
    void on_pin_12_pushButton_clicked();
    void on_pin_13_pushButton_clicked();
    void on_pin_15_pushButton_clicked();
};
#endif // ESP_MQTT_CONFIG_WINDOW_H
