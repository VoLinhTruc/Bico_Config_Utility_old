#ifndef ESP_MQTT_CONFIG_WINDOW_H
#define ESP_MQTT_CONFIG_WINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>

#include "com_port_manager.h"
#include "available_com_port_combobox.h"
#include "application_message_builder_dialog.h"

#define BC_MQSC_COMMAND "BC_MQSC_COMMAND"
#define BC_MQSC_COMMAND_SEPERATOR "-----BC_MQSC_COMMAND_SEPERATOR-----"
#define SETTING_BROKER_INFO "SETTING_BROKER_INFO"
#define SETTING_CONNECT_PACKAGE "SETTING_CONNECT_PACKAGE"
#define SETTING_SUBSCRIBE_PACKAGE "SETTING_SUBSCRIBE_PACKAGE"
#define SETTING_PUBLISH_PACKAGE "SETTING_PUBLISH_PACKAGE"
#define SETTING_ACTIVITY_CONFIG "SETTING_ACTIVITY_CONFIG"
#define SETTING_PINMODE "SETTING_PINMODE"

#define BC_MQSC_GET_PROPERTIES "BC_MQSC_GET_PROPERTIES"
#define BC_MQSC_PROPERTIES "BC_MQSC_PROPERTIES"
#define BROKER_INFO_PROPERTIES "BROKER_INFO_PROPERTIES"
#define CONNECT_PACKAGE_PROPERTIES "CONNECT_PACKAGE_PROPERTIES"
#define SUBSCRIBE_PACKAGE_PROPERTIES "SUBSCRIBE_PACKAGE_PROPERTIES"
#define PUBLISH_PACKAGE_PROPERTIES "PUBLISH_PACKAGE_PROPERTIES"
#define ACTIVITY_CONFIG_PROPERTIES "ACTIVITY_CONFIG_PROPERTIES"
#define PINMODE_PROPERTIES "PINMODE_PROPERTIES"
#define ALL_PROPERTIES "ALL_PROPERTIES"

#define MQTT_ACTION_CONNECT "MQTT_ACTION_CONNECT"
#define MQTT_ACTION_SUBSCRIBE "MQTT_ACTION_SUBSCRIBE"
#define MQTT_ACTION_PUBLISH "MQTT_ACTION_PUBLISH"
#define MQTT_ACTION_UNSUBSCRIBE "MQTT_ACTION_UNSUBSCRIBE"
#define MQTT_ACTION_DISCONNECT "MQTT_ACTION_DISCONNECT"
#define MQTT_ACTION_PING "MQTT_ACTION_PING"

#define BC_MQSC_DEVICE_REBOOT "BC_MQSC_DEVICE_REBOOT"

#ifndef DIGITAL_READ_COMMAND
#define DIGITAL_READ_COMMAND "DIGITAL_READ_COMMAND"
#endif
#ifndef ANALOG_READ_COMMAND
#define ANALOG_READ_COMMAND "ANALOG_READ_COMMAND"
#endif
#ifndef DIGITAL_WRITE_COMMAND
#define DIGITAL_WRITE_COMMAND "DIGITAL_WRITE_COMMAND"
#endif
#ifndef ANALOG_WRITE_COMMAND
#define ANALOG_WRITE_COMMAND "ANALOG_WRITE_COMMAND"
#endif



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
    friend class Application_message_Builder_Dialog;

private:
    Com_Port_Manager *com_port_manager;
    Available_Com_Port_ComboBox *bico_port_list_comboBox;
    QTimer *get_serial_data_timer;
    QMetaObject::Connection get_serial_data_timer_connection;
    Application_message_Builder_Dialog* application_message_builder_dialog;
    QMetaObject::Connection application_message_builder_dialog_accepted_connection;
    QMetaObject::Connection application_message_builder_dialog_rejected_connection;
// Attributes --------------------------

// Methods --------------------------
public:

private:
    void devConstruct();
    void devDestroy();

    void JsonObjectToPlaintText(QJsonObject json_object);

public slots:
    void update_serial_data_to_plaint_text();
    void getResultFromApplicationMessageBuilderDialog();
    void handlingApplicationMessageBuilderDialog();
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
    void on_message_builder_pushButton_clicked();
    void on_get_broker_properties_pushButton_clicked();
    void on_get_connect_properties_pushButton_clicked();
    void on_get_subscribe_properties_pushButton_clicked();
    void on_get_publish_properties_pushButton_clicked();
    void on_get_activity_properties_pushButton_clicked();
    void on_get_pin_mode_properties_pushButton_clicked();
    void on_get_all_properties_pushButton_clicked();
    void on_connect_command_pushButton_clicked();
    void on_subscribe_command_pushButton_clicked();
    void on_publish_command_pushButton_clicked();
    void on_unsubscribe_command_pushButton_clicked();
    void on_disconnect_command_pushButton_clicked();
    void on_ping_command_pushButton_clicked();
    void on_device_reboot_pushButton_clicked();
    void on_digital_read_pin_16_pushButton_clicked();
    void on_digital_read_pin_5_pushButton_clicked();
    void on_digital_read_pin_4_pushButton_clicked();
    void on_digital_read_pin_0_pushButton_clicked();
    void on_digital_read_pin_2_pushButton_clicked();
    void on_digital_read_pin_14_pushButton_clicked();
    void on_digital_read_pin_12_pushButton_clicked();
    void on_digital_read_pin_13_pushButton_clicked();
    void on_digital_read_pin_15_pushButton_clicked();
    void on_digital_write_pin_16_pushButton_clicked();
    void on_digital_write_pin_5_pushButton_clicked();
    void on_digital_write_pin_4_pushButton_clicked();
    void on_digital_write_pin_0_pushButton_clicked();
    void on_digital_write_pin_2_pushButton_clicked();
    void on_digital_write_pin_14_pushButton_clicked();
    void on_digital_write_pin_12_pushButton_clicked();
    void on_digital_write_pin_13_pushButton_clicked();
    void on_digital_write_pin_15_pushButton_clicked();
    void on_analog_write_pin_5_pushButton_clicked();
    void on_analog_write_pin_4_pushButton_clicked();
    void on_analog_write_pin_0_pushButton_clicked();
    void on_analog_write_pin_2_pushButton_clicked();
    void on_analog_write_pin_14_pushButton_clicked();
    void on_analog_write_pin_12_pushButton_clicked();
    void on_analog_write_pin_13_pushButton_clicked();
    void on_analog_write_pin_15_pushButton_clicked();
    void on_analog_read_pin_A0_pushButton_clicked();
};
#endif // ESP_MQTT_CONFIG_WINDOW_H
