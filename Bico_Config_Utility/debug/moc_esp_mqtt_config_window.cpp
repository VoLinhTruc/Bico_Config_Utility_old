/****************************************************************************
** Meta object code from reading C++ file 'esp_mqtt_config_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../esp_mqtt_config_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'esp_mqtt_config_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ESP_MQTT_Config_Window_t {
    QByteArrayData data[70];
    char stringdata0[2479];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ESP_MQTT_Config_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ESP_MQTT_Config_Window_t qt_meta_stringdata_ESP_MQTT_Config_Window = {
    {
QT_MOC_LITERAL(0, 0, 22), // "ESP_MQTT_Config_Window"
QT_MOC_LITERAL(1, 23, 33), // "update_serial_data_to_plaint_..."
QT_MOC_LITERAL(2, 57, 0), // ""
QT_MOC_LITERAL(3, 58, 44), // "getResultFromApplicationMessa..."
QT_MOC_LITERAL(4, 103, 39), // "handlingApplicationMessageBui..."
QT_MOC_LITERAL(5, 143, 29), // "on_connect_pushButton_clicked"
QT_MOC_LITERAL(6, 173, 27), // "on_close_pushButton_clicked"
QT_MOC_LITERAL(7, 201, 31), // "on_file_load_pushButton_clicked"
QT_MOC_LITERAL(8, 233, 31), // "on_file_save_pushButton_clicked"
QT_MOC_LITERAL(9, 265, 32), // "on_submit_all_pushButton_clicked"
QT_MOC_LITERAL(10, 298, 31), // "on_broker_ip_pushButton_clicked"
QT_MOC_LITERAL(11, 330, 33), // "on_broker_port_pushButton_cli..."
QT_MOC_LITERAL(12, 364, 35), // "on_protocol_name_pushButton_c..."
QT_MOC_LITERAL(13, 400, 36), // "on_protocol_level_pushButton_..."
QT_MOC_LITERAL(14, 437, 34), // "on_connect_flag_pushButton_cl..."
QT_MOC_LITERAL(15, 472, 32), // "on_will_topic_pushButton_clicked"
QT_MOC_LITERAL(16, 505, 34), // "on_will_message_pushButton_cl..."
QT_MOC_LITERAL(17, 540, 31), // "on_user_name_pushButton_clicked"
QT_MOC_LITERAL(18, 572, 30), // "on_password_pushButton_clicked"
QT_MOC_LITERAL(19, 603, 34), // "on_topic_filter_pushButton_cl..."
QT_MOC_LITERAL(20, 638, 29), // "on_max_qos_pushButton_clicked"
QT_MOC_LITERAL(21, 668, 38), // "on_broker_info_setting_to_tex..."
QT_MOC_LITERAL(22, 707, 41), // "on_connect_packet_setting_to_..."
QT_MOC_LITERAL(23, 749, 45), // "on_subscribe_packet_setting_t..."
QT_MOC_LITERAL(24, 795, 49), // "on_start_up_general_setting_c..."
QT_MOC_LITERAL(25, 845, 4), // "arg1"
QT_MOC_LITERAL(26, 850, 32), // "on_keep_alive_pushButton_clicked"
QT_MOC_LITERAL(27, 883, 39), // "on_client_identifier_pushButt..."
QT_MOC_LITERAL(28, 923, 38), // "on_password_flag_checkBox_sta..."
QT_MOC_LITERAL(29, 962, 34), // "on_user_flag_checkBox_stateCh..."
QT_MOC_LITERAL(30, 997, 34), // "on_will_flag_checkBox_stateCh..."
QT_MOC_LITERAL(31, 1032, 26), // "on_setting_to_text_clicked"
QT_MOC_LITERAL(32, 1059, 26), // "on_text_to_setting_clicked"
QT_MOC_LITERAL(33, 1086, 48), // "on_publish_general_setting_ch..."
QT_MOC_LITERAL(34, 1135, 34), // "on_publish_flag_pushButton_cl..."
QT_MOC_LITERAL(35, 1170, 32), // "on_topic_name_pushButton_clicked"
QT_MOC_LITERAL(36, 1203, 41), // "on_application_message_pushBu..."
QT_MOC_LITERAL(37, 1245, 31), // "on_push_mode_pushButton_clicked"
QT_MOC_LITERAL(38, 1277, 40), // "on_continous_interval_pushBut..."
QT_MOC_LITERAL(39, 1318, 34), // "on_trigger_type_pushButton_cl..."
QT_MOC_LITERAL(40, 1353, 33), // "on_trigger_pin_pushButton_cli..."
QT_MOC_LITERAL(41, 1387, 39), // "on_uart_trigger_sign_pushButt..."
QT_MOC_LITERAL(42, 1427, 41), // "on_publish_packet_setting_to_..."
QT_MOC_LITERAL(43, 1469, 42), // "on_activity_config_setting_to..."
QT_MOC_LITERAL(44, 1512, 43), // "on_publish_mode_comboBox_curr..."
QT_MOC_LITERAL(45, 1556, 43), // "on_trigger_type_comboBox_curr..."
QT_MOC_LITERAL(46, 1600, 28), // "on_pin_16_pushButton_clicked"
QT_MOC_LITERAL(47, 1629, 27), // "on_pin_5_pushButton_clicked"
QT_MOC_LITERAL(48, 1657, 27), // "on_pin_4_pushButton_clicked"
QT_MOC_LITERAL(49, 1685, 27), // "on_pin_0_pushButton_clicked"
QT_MOC_LITERAL(50, 1713, 27), // "on_pin_2_pushButton_clicked"
QT_MOC_LITERAL(51, 1741, 28), // "on_pin_14_pushButton_clicked"
QT_MOC_LITERAL(52, 1770, 28), // "on_pin_12_pushButton_clicked"
QT_MOC_LITERAL(53, 1799, 28), // "on_pin_13_pushButton_clicked"
QT_MOC_LITERAL(54, 1828, 28), // "on_pin_15_pushButton_clicked"
QT_MOC_LITERAL(55, 1857, 37), // "on_message_builder_pushButton..."
QT_MOC_LITERAL(56, 1895, 43), // "on_get_broker_properties_push..."
QT_MOC_LITERAL(57, 1939, 44), // "on_get_connect_properties_pus..."
QT_MOC_LITERAL(58, 1984, 46), // "on_get_subscribe_properties_p..."
QT_MOC_LITERAL(59, 2031, 44), // "on_get_publish_properties_pus..."
QT_MOC_LITERAL(60, 2076, 45), // "on_get_activity_properties_pu..."
QT_MOC_LITERAL(61, 2122, 45), // "on_get_pin_mode_properties_pu..."
QT_MOC_LITERAL(62, 2168, 40), // "on_get_all_properties_pushBut..."
QT_MOC_LITERAL(63, 2209, 37), // "on_connect_command_pushButton..."
QT_MOC_LITERAL(64, 2247, 39), // "on_subscribe_command_pushButt..."
QT_MOC_LITERAL(65, 2287, 37), // "on_publish_command_pushButton..."
QT_MOC_LITERAL(66, 2325, 41), // "on_unsubscribe_command_pushBu..."
QT_MOC_LITERAL(67, 2367, 40), // "on_disconnect_command_pushBut..."
QT_MOC_LITERAL(68, 2408, 34), // "on_ping_command_pushButton_cl..."
QT_MOC_LITERAL(69, 2443, 35) // "on_device_reboot_pushButton_c..."

    },
    "ESP_MQTT_Config_Window\0"
    "update_serial_data_to_plaint_text\0\0"
    "getResultFromApplicationMessageBuilderDialog\0"
    "handlingApplicationMessageBuilderDialog\0"
    "on_connect_pushButton_clicked\0"
    "on_close_pushButton_clicked\0"
    "on_file_load_pushButton_clicked\0"
    "on_file_save_pushButton_clicked\0"
    "on_submit_all_pushButton_clicked\0"
    "on_broker_ip_pushButton_clicked\0"
    "on_broker_port_pushButton_clicked\0"
    "on_protocol_name_pushButton_clicked\0"
    "on_protocol_level_pushButton_clicked\0"
    "on_connect_flag_pushButton_clicked\0"
    "on_will_topic_pushButton_clicked\0"
    "on_will_message_pushButton_clicked\0"
    "on_user_name_pushButton_clicked\0"
    "on_password_pushButton_clicked\0"
    "on_topic_filter_pushButton_clicked\0"
    "on_max_qos_pushButton_clicked\0"
    "on_broker_info_setting_to_text_clicked\0"
    "on_connect_packet_setting_to_text_clicked\0"
    "on_subscribe_packet_setting_to_text_3_clicked\0"
    "on_start_up_general_setting_checkBox_stateChanged\0"
    "arg1\0on_keep_alive_pushButton_clicked\0"
    "on_client_identifier_pushButton_clicked\0"
    "on_password_flag_checkBox_stateChanged\0"
    "on_user_flag_checkBox_stateChanged\0"
    "on_will_flag_checkBox_stateChanged\0"
    "on_setting_to_text_clicked\0"
    "on_text_to_setting_clicked\0"
    "on_publish_general_setting_checkBox_stateChanged\0"
    "on_publish_flag_pushButton_clicked\0"
    "on_topic_name_pushButton_clicked\0"
    "on_application_message_pushButton_clicked\0"
    "on_push_mode_pushButton_clicked\0"
    "on_continous_interval_pushButton_clicked\0"
    "on_trigger_type_pushButton_clicked\0"
    "on_trigger_pin_pushButton_clicked\0"
    "on_uart_trigger_sign_pushButton_clicked\0"
    "on_publish_packet_setting_to_text_clicked\0"
    "on_activity_config_setting_to_text_clicked\0"
    "on_publish_mode_comboBox_currentTextChanged\0"
    "on_trigger_type_comboBox_currentTextChanged\0"
    "on_pin_16_pushButton_clicked\0"
    "on_pin_5_pushButton_clicked\0"
    "on_pin_4_pushButton_clicked\0"
    "on_pin_0_pushButton_clicked\0"
    "on_pin_2_pushButton_clicked\0"
    "on_pin_14_pushButton_clicked\0"
    "on_pin_12_pushButton_clicked\0"
    "on_pin_13_pushButton_clicked\0"
    "on_pin_15_pushButton_clicked\0"
    "on_message_builder_pushButton_clicked\0"
    "on_get_broker_properties_pushButton_clicked\0"
    "on_get_connect_properties_pushButton_clicked\0"
    "on_get_subscribe_properties_pushButton_clicked\0"
    "on_get_publish_properties_pushButton_clicked\0"
    "on_get_activity_properties_pushButton_clicked\0"
    "on_get_pin_mode_properties_pushButton_clicked\0"
    "on_get_all_properties_pushButton_clicked\0"
    "on_connect_command_pushButton_clicked\0"
    "on_subscribe_command_pushButton_clicked\0"
    "on_publish_command_pushButton_clicked\0"
    "on_unsubscribe_command_pushButton_clicked\0"
    "on_disconnect_command_pushButton_clicked\0"
    "on_ping_command_pushButton_clicked\0"
    "on_device_reboot_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ESP_MQTT_Config_Window[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      67,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  349,    2, 0x0a /* Public */,
       3,    0,  350,    2, 0x0a /* Public */,
       4,    0,  351,    2, 0x0a /* Public */,
       5,    0,  352,    2, 0x08 /* Private */,
       6,    0,  353,    2, 0x08 /* Private */,
       7,    0,  354,    2, 0x08 /* Private */,
       8,    0,  355,    2, 0x08 /* Private */,
       9,    0,  356,    2, 0x08 /* Private */,
      10,    0,  357,    2, 0x08 /* Private */,
      11,    0,  358,    2, 0x08 /* Private */,
      12,    0,  359,    2, 0x08 /* Private */,
      13,    0,  360,    2, 0x08 /* Private */,
      14,    0,  361,    2, 0x08 /* Private */,
      15,    0,  362,    2, 0x08 /* Private */,
      16,    0,  363,    2, 0x08 /* Private */,
      17,    0,  364,    2, 0x08 /* Private */,
      18,    0,  365,    2, 0x08 /* Private */,
      19,    0,  366,    2, 0x08 /* Private */,
      20,    0,  367,    2, 0x08 /* Private */,
      21,    0,  368,    2, 0x08 /* Private */,
      22,    0,  369,    2, 0x08 /* Private */,
      23,    0,  370,    2, 0x08 /* Private */,
      24,    1,  371,    2, 0x08 /* Private */,
      26,    0,  374,    2, 0x08 /* Private */,
      27,    0,  375,    2, 0x08 /* Private */,
      28,    1,  376,    2, 0x08 /* Private */,
      29,    1,  379,    2, 0x08 /* Private */,
      30,    1,  382,    2, 0x08 /* Private */,
      31,    0,  385,    2, 0x08 /* Private */,
      32,    0,  386,    2, 0x08 /* Private */,
      33,    1,  387,    2, 0x08 /* Private */,
      34,    0,  390,    2, 0x08 /* Private */,
      35,    0,  391,    2, 0x08 /* Private */,
      36,    0,  392,    2, 0x08 /* Private */,
      37,    0,  393,    2, 0x08 /* Private */,
      38,    0,  394,    2, 0x08 /* Private */,
      39,    0,  395,    2, 0x08 /* Private */,
      40,    0,  396,    2, 0x08 /* Private */,
      41,    0,  397,    2, 0x08 /* Private */,
      42,    0,  398,    2, 0x08 /* Private */,
      43,    0,  399,    2, 0x08 /* Private */,
      44,    1,  400,    2, 0x08 /* Private */,
      45,    1,  403,    2, 0x08 /* Private */,
      46,    0,  406,    2, 0x08 /* Private */,
      47,    0,  407,    2, 0x08 /* Private */,
      48,    0,  408,    2, 0x08 /* Private */,
      49,    0,  409,    2, 0x08 /* Private */,
      50,    0,  410,    2, 0x08 /* Private */,
      51,    0,  411,    2, 0x08 /* Private */,
      52,    0,  412,    2, 0x08 /* Private */,
      53,    0,  413,    2, 0x08 /* Private */,
      54,    0,  414,    2, 0x08 /* Private */,
      55,    0,  415,    2, 0x08 /* Private */,
      56,    0,  416,    2, 0x08 /* Private */,
      57,    0,  417,    2, 0x08 /* Private */,
      58,    0,  418,    2, 0x08 /* Private */,
      59,    0,  419,    2, 0x08 /* Private */,
      60,    0,  420,    2, 0x08 /* Private */,
      61,    0,  421,    2, 0x08 /* Private */,
      62,    0,  422,    2, 0x08 /* Private */,
      63,    0,  423,    2, 0x08 /* Private */,
      64,    0,  424,    2, 0x08 /* Private */,
      65,    0,  425,    2, 0x08 /* Private */,
      66,    0,  426,    2, 0x08 /* Private */,
      67,    0,  427,    2, 0x08 /* Private */,
      68,    0,  428,    2, 0x08 /* Private */,
      69,    0,  429,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ESP_MQTT_Config_Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ESP_MQTT_Config_Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_serial_data_to_plaint_text(); break;
        case 1: _t->getResultFromApplicationMessageBuilderDialog(); break;
        case 2: _t->handlingApplicationMessageBuilderDialog(); break;
        case 3: _t->on_connect_pushButton_clicked(); break;
        case 4: _t->on_close_pushButton_clicked(); break;
        case 5: _t->on_file_load_pushButton_clicked(); break;
        case 6: _t->on_file_save_pushButton_clicked(); break;
        case 7: _t->on_submit_all_pushButton_clicked(); break;
        case 8: _t->on_broker_ip_pushButton_clicked(); break;
        case 9: _t->on_broker_port_pushButton_clicked(); break;
        case 10: _t->on_protocol_name_pushButton_clicked(); break;
        case 11: _t->on_protocol_level_pushButton_clicked(); break;
        case 12: _t->on_connect_flag_pushButton_clicked(); break;
        case 13: _t->on_will_topic_pushButton_clicked(); break;
        case 14: _t->on_will_message_pushButton_clicked(); break;
        case 15: _t->on_user_name_pushButton_clicked(); break;
        case 16: _t->on_password_pushButton_clicked(); break;
        case 17: _t->on_topic_filter_pushButton_clicked(); break;
        case 18: _t->on_max_qos_pushButton_clicked(); break;
        case 19: _t->on_broker_info_setting_to_text_clicked(); break;
        case 20: _t->on_connect_packet_setting_to_text_clicked(); break;
        case 21: _t->on_subscribe_packet_setting_to_text_3_clicked(); break;
        case 22: _t->on_start_up_general_setting_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_keep_alive_pushButton_clicked(); break;
        case 24: _t->on_client_identifier_pushButton_clicked(); break;
        case 25: _t->on_password_flag_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_user_flag_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_will_flag_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_setting_to_text_clicked(); break;
        case 29: _t->on_text_to_setting_clicked(); break;
        case 30: _t->on_publish_general_setting_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->on_publish_flag_pushButton_clicked(); break;
        case 32: _t->on_topic_name_pushButton_clicked(); break;
        case 33: _t->on_application_message_pushButton_clicked(); break;
        case 34: _t->on_push_mode_pushButton_clicked(); break;
        case 35: _t->on_continous_interval_pushButton_clicked(); break;
        case 36: _t->on_trigger_type_pushButton_clicked(); break;
        case 37: _t->on_trigger_pin_pushButton_clicked(); break;
        case 38: _t->on_uart_trigger_sign_pushButton_clicked(); break;
        case 39: _t->on_publish_packet_setting_to_text_clicked(); break;
        case 40: _t->on_activity_config_setting_to_text_clicked(); break;
        case 41: _t->on_publish_mode_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 42: _t->on_trigger_type_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 43: _t->on_pin_16_pushButton_clicked(); break;
        case 44: _t->on_pin_5_pushButton_clicked(); break;
        case 45: _t->on_pin_4_pushButton_clicked(); break;
        case 46: _t->on_pin_0_pushButton_clicked(); break;
        case 47: _t->on_pin_2_pushButton_clicked(); break;
        case 48: _t->on_pin_14_pushButton_clicked(); break;
        case 49: _t->on_pin_12_pushButton_clicked(); break;
        case 50: _t->on_pin_13_pushButton_clicked(); break;
        case 51: _t->on_pin_15_pushButton_clicked(); break;
        case 52: _t->on_message_builder_pushButton_clicked(); break;
        case 53: _t->on_get_broker_properties_pushButton_clicked(); break;
        case 54: _t->on_get_connect_properties_pushButton_clicked(); break;
        case 55: _t->on_get_subscribe_properties_pushButton_clicked(); break;
        case 56: _t->on_get_publish_properties_pushButton_clicked(); break;
        case 57: _t->on_get_activity_properties_pushButton_clicked(); break;
        case 58: _t->on_get_pin_mode_properties_pushButton_clicked(); break;
        case 59: _t->on_get_all_properties_pushButton_clicked(); break;
        case 60: _t->on_connect_command_pushButton_clicked(); break;
        case 61: _t->on_subscribe_command_pushButton_clicked(); break;
        case 62: _t->on_publish_command_pushButton_clicked(); break;
        case 63: _t->on_unsubscribe_command_pushButton_clicked(); break;
        case 64: _t->on_disconnect_command_pushButton_clicked(); break;
        case 65: _t->on_ping_command_pushButton_clicked(); break;
        case 66: _t->on_device_reboot_pushButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ESP_MQTT_Config_Window::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_ESP_MQTT_Config_Window.data,
    qt_meta_data_ESP_MQTT_Config_Window,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ESP_MQTT_Config_Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ESP_MQTT_Config_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ESP_MQTT_Config_Window.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ESP_MQTT_Config_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 67)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 67;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 67)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 67;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
