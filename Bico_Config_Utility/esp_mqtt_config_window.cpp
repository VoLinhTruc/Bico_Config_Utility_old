#include "esp_mqtt_config_window.h"
#include "ui_esp_mqtt_config_window.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTimer>
#include <QTextCursor>
#include <QScrollBar>
#include <QRandomGenerator>



//Dev's defination ----------------------------------------------------------------------------------------
void ESP_MQTT_Config_Window::devConstruct()
{
    // delete ESP_Wifi_Config_Window if press the X to close window
    // ESP_Wifi_Config_Window still exist if we don't execute setAttribute(Qt::WA_DeleteOnClose);
    setAttribute(Qt::WA_DeleteOnClose);

    com_port_manager = new Com_Port_Manager(this);
    bico_port_list_comboBox = new Available_Com_Port_ComboBox(ui->port_list_comboBox);

    get_serial_data_timer = new QTimer(this);
    get_serial_data_timer->setInterval(1);
    get_serial_data_timer_connection = connect(get_serial_data_timer, SIGNAL(timeout()), this, SLOT(update_serial_data_to_plaint_text()));


    ui->start_up_general_setting_checkBox->setChecked(true);
    on_will_flag_checkBox_stateChanged(0);
    on_publish_mode_comboBox_currentTextChanged(QString("Continous"));
}

void ESP_MQTT_Config_Window::devDestroy()
{
    disconnect(get_serial_data_timer_connection);
}

void ESP_MQTT_Config_Window::JsonObjectToPlaintText(QJsonObject json_object)
{
    QJsonDocument json_doc(json_object);
    com_port_manager->print(QString(json_doc.toJson()));

    if(ui->append_content_checkBox->isChecked())
    {
        ui->configuration_data_plainTextEdit->appendPlainText(BC_MQSC_COMMAND_SEPERATOR);
        ui->configuration_data_plainTextEdit->appendPlainText(QString(json_doc.toJson()));
    }
    else
    {
        ui->configuration_data_plainTextEdit->setPlainText(QString(json_doc.toJson()));
    }
}

void ESP_MQTT_Config_Window::update_serial_data_to_plaint_text()
{
    if(com_port_manager->available() > 0)
    {
        QString temp_string = ui->data_from_com_port_plainTextEdit->toPlainText()+QString(com_port_manager->read());
        ui->data_from_com_port_plainTextEdit->setPlainText(temp_string);
        ui->data_from_com_port_plainTextEdit->verticalScrollBar()->setValue(ui->data_from_com_port_plainTextEdit->verticalScrollBar()->maximum());
    }
}

// No using this anymore because I have puted setAttribute(Qt::WA_DeleteOnClose); in devInit()
//void ESP_Wifi_Config_Window::closeEvent(QCloseEvent *event)
//{
//    QMainWindow::closeEvent(event);
//    comport_check_timer->disconnect(comport_check_timer, SIGNAL(timeout()), this, SLOT(pollingComPort()));
//}

//Dev's defination ----------------------------------------------------------------------------------------



ESP_MQTT_Config_Window::ESP_MQTT_Config_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ESP_MQTT_Config_Window)
{
    ui->setupUi(this);
    devConstruct();
}

ESP_MQTT_Config_Window::~ESP_MQTT_Config_Window()
{
    devDestroy();
    delete ui;
}

void ESP_MQTT_Config_Window::on_connect_pushButton_clicked()
{
    if(com_port_manager->begin(bico_port_list_comboBox->currentText().section(',', 0, 0), ui->baudrate_comboBox->currentText().toLong()))
    {
        ui->connect_state_label->setText("Connected");
        get_serial_data_timer->start();
    }
}

void ESP_MQTT_Config_Window::on_close_pushButton_clicked()
{
    com_port_manager->end();
    ui->connect_state_label->setText("Disconnected");
    get_serial_data_timer->stop();
}

void ESP_MQTT_Config_Window::on_file_load_pushButton_clicked()
{
    // convert file_path_lineEdit text to QString
    QString file_path_lineEdit;
    file_path_lineEdit = ui->file_path_lineEdit->text();
    if(file_path_lineEdit == "")
    {
        file_path_lineEdit = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath(), "Text files (*.txt *.json)");
         ui->file_path_lineEdit->setText(file_path_lineEdit);
    }

    // open file via above QString
    QFile file(file_path_lineEdit);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(Q_NULLPTR, "Info", file.errorString());
    }
    else
    {
        // read all from file and pass content to setPlainText
        ui->configuration_data_plainTextEdit->setPlainText(file.readAll());

        // close file
        file.close();
    }
}

void ESP_MQTT_Config_Window::on_file_save_pushButton_clicked()
{
    // convert file_path_lineEdit text to QString
    QString file_path_lineEdit;
    file_path_lineEdit = ui->file_path_lineEdit->text();
    if(file_path_lineEdit == "")
    {
        file_path_lineEdit = QFileDialog::getSaveFileName(this, "Save configuration", QDir::currentPath(), "Text files (*.txt *.json)");
    }

    // open file via above QString
    QFile file(file_path_lineEdit);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(Q_NULLPTR, "Info", file.errorString());
    }
    else
    {
        // create stream to set file content by content of file_content_plainTextEdit
        QTextStream content_to_file(&file);
        content_to_file << ui->configuration_data_plainTextEdit->toPlainText();

        // close file
        file.close();
    }
}

void ESP_MQTT_Config_Window::on_submit_all_pushButton_clicked()
{
    com_port_manager->print(ui->configuration_data_plainTextEdit->toPlainText().toUtf8());
}

void ESP_MQTT_Config_Window::on_broker_ip_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_BROKER_INFO;
    (temp_json_obj)["_broker_ip_address"] = ui->broker_ip_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_broker_port_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_BROKER_INFO;
    (temp_json_obj)["_broker_port"] = ui->broker_port_lineEdit->text().toInt();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_protocol_name_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["protocol_name"] = ui->protocol_name_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_protocol_level_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["protocol_level"] = ui->protocol_level_lineEdit->text().toInt();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_connect_flag_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["clean_sesion"] = uint8_t(ui->clean_session_checkBox->isChecked());
    (temp_json_obj)["will_retain"] = uint8_t(ui->will_retain_checkBox->isChecked());
    (temp_json_obj)["password"] = uint8_t(ui->password_flag_checkBox->isChecked());
    (temp_json_obj)["user_name"] = uint8_t(ui->user_flag_checkBox->isChecked());
    (temp_json_obj)["will_flag"] = uint8_t(ui->will_flag_checkBox->isChecked());
    (temp_json_obj)["will_QoS"] = ui->will_qos_comboBox->currentText().toInt();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_keep_alive_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["keep_alive"] = ui->keep_alive_lineEdit->text().toInt();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_client_identifier_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["client_identifier"] = ui->client_identifier_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_will_topic_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["will_topic"] = ui->will_topic_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_will_message_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["will_message"] = ui->will_message_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_user_name_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["User_name"] = ui->user_name_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_password_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["Password"] = ui->password_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_topic_filter_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_SUBSCRIBE_PACKAGE;
    (temp_json_obj)["topic_filter"] = ui->topic_filter_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_max_qos_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_SUBSCRIBE_PACKAGE;
    (temp_json_obj)["max_QoS"] = ui->max_qos_comboBox->currentText().toInt();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_broker_info_setting_to_text_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_BROKER_INFO;
    (temp_json_obj)["_broker_ip_address"] = ui->broker_ip_lineEdit->text();
    (temp_json_obj)["_broker_port"] = ui->broker_port_lineEdit->text().toInt();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_connect_packet_setting_to_text_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["protocol_name"] = ui->protocol_name_lineEdit->text();
    (temp_json_obj)["protocol_level"] = ui->protocol_level_lineEdit->text().toInt();
    (temp_json_obj)["clean_sesion"] = uint8_t(ui->clean_session_checkBox->isChecked());
    (temp_json_obj)["will_retain"] = uint8_t(ui->will_retain_checkBox->isChecked());
    (temp_json_obj)["password"] = uint8_t(ui->password_flag_checkBox->isChecked());
    (temp_json_obj)["user_name"] = uint8_t(ui->user_flag_checkBox->isChecked());
    (temp_json_obj)["keep_alive"] = ui->keep_alive_lineEdit->text().toInt();
    (temp_json_obj)["client_identifier"] = ui->client_identifier_lineEdit->text();
    (temp_json_obj)["will_flag"] = uint8_t(ui->will_flag_checkBox->isChecked());
    (temp_json_obj)["will_QoS"] = ui->will_qos_comboBox->currentText().toInt();
    (temp_json_obj)["will_topic"] = ui->will_topic_lineEdit->text();
    (temp_json_obj)["will_message"] = ui->will_message_lineEdit->text();
    (temp_json_obj)["User_name"] = ui->user_name_lineEdit->text();
    (temp_json_obj)["Password"] = ui->password_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_subscribe_packet_setting_to_text_3_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_SUBSCRIBE_PACKAGE;
    (temp_json_obj)["topic_filter"] = ui->topic_filter_lineEdit->text();
    (temp_json_obj)["max_QoS"] = ui->max_qos_comboBox->currentText().toInt();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_start_up_general_setting_checkBox_stateChanged(int arg1)
{
    ui->clean_session_checkBox->setChecked(bool(arg1));
    ui->user_flag_checkBox->setChecked(bool(arg1));
    ui->password_flag_checkBox->setChecked(bool(arg1));

    if(arg1)
    {
        ui->protocol_name_lineEdit->setText("MQTT");
        ui->protocol_level_lineEdit->setText("4");
        ui->keep_alive_lineEdit->setText("60");
        ui->client_identifier_lineEdit->setText(QString("client_")+QString::number(QRandomGenerator::global()->bounded(0, 10))+QString::number(QRandomGenerator::global()->bounded(0, 10))+QString::number(QRandomGenerator::global()->bounded(0, 10))+QString::number(QRandomGenerator::global()->bounded(0, 10)));
    }
    else
    {
        ui->protocol_name_lineEdit->setText("");
        ui->protocol_level_lineEdit->setText("");
        ui->keep_alive_lineEdit->setText("");
        ui->client_identifier_lineEdit->setText("");
    }
}

void ESP_MQTT_Config_Window::on_password_flag_checkBox_stateChanged(int arg1)
{
    ui->password_lineEdit->setEnabled(bool(arg1));
    ui->password_pushButton->setEnabled(bool(arg1));
}

void ESP_MQTT_Config_Window::on_user_flag_checkBox_stateChanged(int arg1)
{
    ui->user_name_lineEdit->setEnabled(bool(arg1));
    ui->user_name_pushButton->setEnabled(bool(arg1));
}

void ESP_MQTT_Config_Window::on_will_flag_checkBox_stateChanged(int arg1)
{
    ui->will_qos_comboBox->setEnabled(bool(arg1));
    ui->will_topic_lineEdit->setEnabled(bool(arg1));
    ui->will_topic_pushButton->setEnabled(bool(arg1));
    ui->will_message_lineEdit->setEnabled(bool(arg1));
    ui->will_message_pushButton->setEnabled(bool(arg1));
}

void ESP_MQTT_Config_Window::on_setting_to_text_clicked()
{
    if(ui->setting_tabWidget->currentWidget()->objectName() == QString("start_up_tab"))
    {
        if(!(ui->append_content_checkBox->isChecked()))
        {
            on_broker_info_setting_to_text_clicked();
            ui->append_content_checkBox->setChecked(true);
            on_connect_packet_setting_to_text_clicked();
            on_subscribe_packet_setting_to_text_3_clicked();
            ui->append_content_checkBox->setChecked(false);
        }
        else
        {
            on_broker_info_setting_to_text_clicked();
            on_connect_packet_setting_to_text_clicked();
            on_subscribe_packet_setting_to_text_3_clicked();
        }
    }
    else if(ui->setting_tabWidget->currentWidget()->objectName() == QString("publish_tab"))
    {
        if(!(ui->append_content_checkBox->isChecked()))
        {
            on_publish_packet_setting_to_text_clicked();
            ui->append_content_checkBox->setChecked(true);
            on_activity_config_setting_to_text_clicked();
            ui->append_content_checkBox->setChecked(false);
        }
        else
        {
            on_publish_packet_setting_to_text_clicked();
            on_activity_config_setting_to_text_clicked();
        }
    }
}

void ESP_MQTT_Config_Window::on_text_to_setting_clicked()
{
    QString ex_str = ui->configuration_data_plainTextEdit->toPlainText();

    while(ex_str.indexOf(BC_MQSC_COMMAND) != -1)
    {
        QString str;

        if(ex_str.indexOf(BC_MQSC_COMMAND_SEPERATOR) != -1)
        {
            str = ex_str.mid(0, ex_str.indexOf(BC_MQSC_COMMAND_SEPERATOR));
            ex_str.remove(0, ex_str.indexOf(BC_MQSC_COMMAND_SEPERATOR) + QString(BC_MQSC_COMMAND_SEPERATOR).length());
        }
        else
        {
            str = ex_str;
            ex_str = "";
        }

        if(str.indexOf(BC_MQSC_COMMAND) != -1)
        {
            QJsonDocument json_doc = QJsonDocument::fromJson(str.toUtf8());
            if(!json_doc.isNull())
            {
                QJsonObject json_obj = json_doc.object();
                QString command = json_obj[BC_MQSC_COMMAND].toString();

                if(command == QString(SETTING_BROKER_INFO))
                {
                    if(json_obj.contains("_broker_ip_address"))
                    {
                        ui->broker_ip_lineEdit->setText(json_obj["_broker_ip_address"].toString());
                    }

                    if(json_obj.contains("_broker_port"))
                    {
                        ui->broker_port_lineEdit->setText(QString::number(json_obj["_broker_port"].toInt()));
                    }
                }

                else if(command == QString(SETTING_CONNECT_PACKAGE))
                {
                    if(json_obj.contains("Password"))
                    {
                        ui->password_lineEdit->setText(json_obj["Password"].toString());
                    }

                    if(json_obj.contains("User_name"))
                    {
                        ui->user_name_lineEdit->setText(json_obj["User_name"].toString());
                    }

                    if(json_obj.contains("clean_sesion"))
                    {
                        ui->clean_session_checkBox->setChecked(!!(json_obj["clean_sesion"].toInt()));
                    }

                    if(json_obj.contains("client_identifier"))
                    {
                        ui->client_identifier_lineEdit->setText(json_obj["client_identifier"].toString());
                    }

                    if(json_obj.contains("keep_alive"))
                    {
                        ui->keep_alive_lineEdit->setText(QString(QString::number(json_obj["keep_alive"].toInt())));
                    }

                    if(json_obj.contains("password"))
                    {
                        ui->password_flag_checkBox->setChecked(!!(json_obj["password"].toInt()));
                    }

                    if(json_obj.contains("protocol_level"))
                    {
                        ui->protocol_level_lineEdit->setText(QString(QString::number(json_obj["protocol_level"].toInt())));
                    }

                    if(json_obj.contains("protocol_name"))
                    {
                        ui->protocol_name_lineEdit->setText(json_obj["protocol_name"].toString());
                    }

                    if(json_obj.contains("user_name"))
                    {
                       ui->user_flag_checkBox->setChecked(!!(json_obj["user_name"].toInt()));
                    }

                    if(json_obj.contains("will_QoS"))
                    {
                        ui->will_qos_comboBox->setCurrentText(QString(QString::number(json_obj["will_QoS"].toInt())));
                    }

                    if(json_obj.contains("will_flag"))
                    {
                        ui->will_flag_checkBox->setChecked(!!(json_obj["will_flag"].toInt()));
                    }

                    if(json_obj.contains("will_message"))
                    {
                        ui->will_message_lineEdit->setText(json_obj["will_message"].toString());
                    }

                    if(json_obj.contains("will_retain"))
                    {
                        ui->will_retain_checkBox->setChecked(!!(json_obj["will_retain"].toInt()));
                    }

                    if(json_obj.contains("will_topic"))
                    {
                        ui->will_topic_lineEdit->setText(json_obj["will_topic"].toString());
                    }
                }

                else if(command == QString(SETTING_SUBSCRIBE_PACKAGE))
                {
                    if(json_obj.contains("max_QoS"))
                    {
                        ui->max_qos_comboBox->setCurrentText(QString(QString::number(json_obj["max_QoS"].toInt())));
                    }

                    if(json_obj.contains("topic_filter"))
                    {
                        ui->topic_filter_lineEdit->setText(json_obj["topic_filter"].toString());
                    }
                }

                else if(command == QString(SETTING_PUBLISH_PACKAGE))
                {
                    if(json_obj.contains("QoS"))
                    {
                        ui->qos_level_comboBox->setCurrentText(QString(QString::number(json_obj["QoS"].toInt())));
                    }

                    if(json_obj.contains("application_message"))
                    {
                        ui->application_message_plainTextEdit->setPlainText(json_obj["application_message"].toString());
                    }

                    if(json_obj.contains("dup"))
                    {
                        ui->dup_flag_checkBox->setChecked(!!(json_obj["dup"].toInt()));
                    }

                    if(json_obj.contains("retain"))
                    {
                        ui->retain_checkBox->setChecked(!!(json_obj["retain"].toInt()));
                    }

                    if(json_obj.contains("topic_name"))
                    {
                        ui->topic_name_lineEdit->setText(json_obj["topic_name"].toString());
                    }
                }

                else if(command == QString(SETTING_ACTIVITY_CONFIG))
                {
                    if(json_obj.contains("_publish_continuous_interval"))
                    {
                        ui->continous_interval_lineEdit->setText(QString::number(json_obj["_publish_continuous_interval"].toInt()));
                    }

                    if(json_obj.contains("_publish_running_mode"))
                    {
                        if(json_obj["_publish_running_mode"].toInt() == CONTINUOUS)
                        {
                            ui->publish_mode_comboBox->setCurrentText("Continous");
                        }
                        else if(json_obj["_publish_running_mode"].toInt() == TRIGGER)
                        {
                            ui->publish_mode_comboBox->setCurrentText("Trigger");
                        }
                    }

                    if(json_obj.contains("_publish_trigger_pin"))
                    {
                        ui->trigger_pin_lineEdit->setText(QString::number(json_obj["_publish_trigger_pin"].toInt()));
                    }

                    if(json_obj.contains("_publish_trigger_sign"))
                    {
                        ui->uart_trigger_sign_lineEdit->setText(json_obj["_publish_trigger_sign"].toString().mid(0, 1));
                    }

                    if(json_obj.contains("_publish_trigger_type"))
                    {
                        if(json_obj["_publish_trigger_type"].toInt() == RISING_AND_FALLING_TRIGGER)
                        {
                            ui->trigger_type_comboBox->setCurrentText("Rising or Falling");
                        }
                        else if(json_obj["_publish_trigger_type"].toInt() == RISING_TRIGGER)
                        {
                            ui->trigger_type_comboBox->setCurrentText("Rising");
                        }
                        else if(json_obj["_publish_trigger_type"].toInt() == FALLING_TRIGGER)
                        {
                            ui->trigger_type_comboBox->setCurrentText("Falling");
                        }
                    }
                }
            }
            else
            {
                QMessageBox::information(Q_NULLPTR, "Info", "Invalid JSON");
            }
        }
    }
}

void ESP_MQTT_Config_Window::on_publish_general_setting_checkBox_stateChanged(int arg1)
{
    if(!!arg1)
    {
        ui->retain_checkBox->setChecked(false);
        ui->dup_flag_checkBox->setChecked(false);
        ui->qos_level_comboBox->setCurrentText("0");

        ui->publish_mode_comboBox->setCurrentText("Continous");
        ui->continous_interval_lineEdit->setText("5000");
    }
    else
    {
        ui->retain_checkBox->setChecked(false);
        ui->dup_flag_checkBox->setChecked(false);
        ui->qos_level_comboBox->setCurrentText("0");

        ui->publish_mode_comboBox->setCurrentText("");
        ui->continous_interval_lineEdit->setText("");
    }
}

void ESP_MQTT_Config_Window::on_publish_flag_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_PUBLISH_PACKAGE;
    (temp_json_obj)["retain"] = uint8_t(ui->retain_checkBox->isChecked());
    (temp_json_obj)["QoS"] = ui->qos_level_comboBox->currentText().toInt();
    (temp_json_obj)["dup"] = uint8_t(ui->dup_flag_checkBox->isChecked());

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_topic_name_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_PUBLISH_PACKAGE;
    (temp_json_obj)["topic_name"] = ui->topic_name_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_application_message_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_PUBLISH_PACKAGE;
    (temp_json_obj)["application_message"] = ui->application_message_plainTextEdit->toPlainText();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_push_mode_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_ACTIVITY_CONFIG;
    if(ui->publish_mode_comboBox->currentText() == QString("Continous"))
    {
        (temp_json_obj)["_publish_running_mode"] = CONTINUOUS;
    }
    else if(ui->publish_mode_comboBox->currentText() == QString("Trigger"))
    {
        (temp_json_obj)["_publish_running_mode"] = TRIGGER;
    }

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_continous_interval_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_ACTIVITY_CONFIG;
    (temp_json_obj)["_publish_continuous_interval"] = ui->continous_interval_lineEdit->text().toInt();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_trigger_type_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_ACTIVITY_CONFIG;
    if(ui->trigger_type_comboBox->currentText() == QString("Rising or Falling"))
    {
        (temp_json_obj)["_publish_trigger_type"] = RISING_AND_FALLING_TRIGGER;
    }
    else if(ui->trigger_type_comboBox->currentText() == QString("Rising"))
    {
        (temp_json_obj)["_publish_trigger_type"] = RISING_TRIGGER;
    }
    else if(ui->trigger_type_comboBox->currentText() == QString("Falling"))
    {
        (temp_json_obj)["_publish_trigger_type"] = FALLING_TRIGGER;
    }

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_trigger_pin_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_ACTIVITY_CONFIG;
    (temp_json_obj)["_publish_trigger_pin"] = ui->trigger_pin_lineEdit->text().toInt();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_uart_trigger_sign_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_ACTIVITY_CONFIG;

    if(ui->uart_trigger_sign_lineEdit->text() != QString(""))
    {
        (temp_json_obj)["_publish_trigger_sign"] = ui->uart_trigger_sign_lineEdit->text().at(0).toLatin1();
    }
    else
    {
        (temp_json_obj)["_publish_trigger_sign"] = 0;
    }

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_publish_packet_setting_to_text_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_PUBLISH_PACKAGE;
    (temp_json_obj)["retain"] = uint8_t(ui->retain_checkBox->isChecked());
    (temp_json_obj)["QoS"] = ui->qos_level_comboBox->currentText().toInt();
    (temp_json_obj)["dup"] = uint8_t(ui->dup_flag_checkBox->isChecked());

    (temp_json_obj)["topic_name"] = ui->topic_name_lineEdit->text();
    (temp_json_obj)["application_message"] = ui->application_message_plainTextEdit->toPlainText();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_activity_config_setting_to_text_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_ACTIVITY_CONFIG;

    if(ui->publish_mode_comboBox->currentText() == QString("Continous"))
    {
        (temp_json_obj)["_publish_running_mode"] = CONTINUOUS;
    }
    else if(ui->publish_mode_comboBox->currentText() == QString("Trigger"))
    {
        (temp_json_obj)["_publish_running_mode"] = TRIGGER;
    }

    (temp_json_obj)["_publish_continuous_interval"] = ui->continous_interval_lineEdit->text().toInt();

    if(ui->trigger_type_comboBox->currentText() == QString("Rising or Falling"))
    {
        (temp_json_obj)["_publish_trigger_type"] = RISING_AND_FALLING_TRIGGER;
    }
    else if(ui->trigger_type_comboBox->currentText() == QString("Rising"))
    {
        (temp_json_obj)["_publish_trigger_type"] = RISING_TRIGGER;
    }
    else if(ui->trigger_type_comboBox->currentText() == QString("Falling"))
    {
        (temp_json_obj)["_publish_trigger_type"] = FALLING_TRIGGER;
    }

    (temp_json_obj)["_publish_trigger_pin"] = ui->trigger_pin_lineEdit->text().toInt();

    if(ui->uart_trigger_sign_lineEdit->text() != QString(""))
    {
        (temp_json_obj)["_publish_trigger_sign"] = ui->uart_trigger_sign_lineEdit->text().mid(0, 1);
    }
    else
    {
        (temp_json_obj)["_publish_trigger_sign"] = "";
    }

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_MQTT_Config_Window::on_publish_mode_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == QString("Continous"))
    {
        ui->continous_interval_lineEdit->setEnabled(true);
        ui->trigger_type_comboBox->setEnabled(false);
        ui->trigger_pin_lineEdit->setEnabled(false);
        ui->uart_trigger_sign_lineEdit->setEnabled(false);
    }
    else if(arg1 == QString("Trigger"))
    {
        ui->continous_interval_lineEdit->setEnabled(false);
        ui->trigger_type_comboBox->setEnabled(true);
        ui->trigger_pin_lineEdit->setEnabled(true);
        ui->uart_trigger_sign_lineEdit->setEnabled(true);
    }
}

void ESP_MQTT_Config_Window::on_trigger_type_comboBox_currentTextChanged(const QString &arg1)
{

}
