#include "esp_mqtt_config_window.h"
#include "ui_esp_mqtt_config_window.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTimer>
#include <QTextCursor>
#include <QScrollBar>



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
}

void ESP_MQTT_Config_Window::devDestroy()
{
    disconnect(get_serial_data_timer_connection);
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

    QJsonDocument json_doc(temp_json_obj);
    com_port_manager->print(QString(json_doc.toJson()));

    ui->configuration_data_plainTextEdit->setPlainText(QString(json_doc.toJson()));
}

void ESP_MQTT_Config_Window::on_broker_port_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_BROKER_INFO;
    (temp_json_obj)["_broker_port"] = ui->broker_port_lineEdit->text().toInt();

    QJsonDocument json_doc(temp_json_obj);
    com_port_manager->print(QString(json_doc.toJson()));

    ui->configuration_data_plainTextEdit->setPlainText(QString(json_doc.toJson()));
}

void ESP_MQTT_Config_Window::on_protocol_name_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["protocol_name"] = ui->protocol_name_lineEdit->text();

    QJsonDocument json_doc(temp_json_obj);
    com_port_manager->print(QString(json_doc.toJson()));

    ui->configuration_data_plainTextEdit->setPlainText(QString(json_doc.toJson()));
}

void ESP_MQTT_Config_Window::on_protocol_level_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["protocol_level"] = ui->protocol_level_lineEdit->text().toInt();

    QJsonDocument json_doc(temp_json_obj);
    com_port_manager->print(QString(json_doc.toJson()));

    ui->configuration_data_plainTextEdit->setPlainText(QString(json_doc.toJson()));
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

    QJsonDocument json_doc(temp_json_obj);
    com_port_manager->print(QString(json_doc.toJson()));

    ui->configuration_data_plainTextEdit->setPlainText(QString(json_doc.toJson()));
}

void ESP_MQTT_Config_Window::on_will_topic_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["will_topic"] = ui->will_topic_lineEdit->text();

    QJsonDocument json_doc(temp_json_obj);
    com_port_manager->print(QString(json_doc.toJson()));

    ui->configuration_data_plainTextEdit->setPlainText(QString(json_doc.toJson()));
}

void ESP_MQTT_Config_Window::on_will_message_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["will_message"] = ui->will_message_lineEdit->text();

    QJsonDocument json_doc(temp_json_obj);
    com_port_manager->print(QString(json_doc.toJson()));

    ui->configuration_data_plainTextEdit->setPlainText(QString(json_doc.toJson()));
}

void ESP_MQTT_Config_Window::on_user_name_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["User_name"] = ui->user_name_lineEdit->text();

    QJsonDocument json_doc(temp_json_obj);
    com_port_manager->print(QString(json_doc.toJson()));

    ui->configuration_data_plainTextEdit->setPlainText(QString(json_doc.toJson()));
}

void ESP_MQTT_Config_Window::on_password_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_CONNECT_PACKAGE;
    (temp_json_obj)["Password"] = ui->password_lineEdit->text();

    QJsonDocument json_doc(temp_json_obj);
    com_port_manager->print(QString(json_doc.toJson()));

    ui->configuration_data_plainTextEdit->setPlainText(QString(json_doc.toJson()));
}

void ESP_MQTT_Config_Window::on_topic_filter_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_SUBSCRIBE_PACKAGE;
    (temp_json_obj)["topic_filter"] = ui->topic_filter_lineEdit->text();

    QJsonDocument json_doc(temp_json_obj);
    com_port_manager->print(QString(json_doc.toJson()));

    ui->configuration_data_plainTextEdit->setPlainText(QString(json_doc.toJson()));
}

void ESP_MQTT_Config_Window::on_max_qos_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_MQSC_COMMAND] = SETTING_SUBSCRIBE_PACKAGE;
    (temp_json_obj)["max_QoS"] = ui->max_qos_comboBox->currentText().toInt();

    QJsonDocument json_doc(temp_json_obj);
    com_port_manager->print(QString(json_doc.toJson()));

    ui->configuration_data_plainTextEdit->setPlainText(QString(json_doc.toJson()));
}
