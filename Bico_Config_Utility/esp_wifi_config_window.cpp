#include "esp_wifi_config_window.h"
#include "ui_esp_wifi_config_window.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QTimer>
#include <QTextCursor>
#include <QScrollBar>



//Dev's defination ----------------------------------------------------------------------------------------
void ESP_Wifi_Config_Window::devConstruct()
{
    // delete ESP_Wifi_Config_Window if press the X to close window
    // ESP_Wifi_Config_Window still exist if we don't execute setAttribute(Qt::WA_DeleteOnClose);
    setAttribute(Qt::WA_DeleteOnClose);

    com_port_manager = new Com_Port_Manager(this);

    bico_port_list_comboBox = new Available_Com_Port_ComboBox(ui->port_list_comboBox);
    QList<QSerialPortInfo> list = QSerialPortInfo::availablePorts();
    for(int i = 0; i < list.size(); i++)
    {
        bico_port_list_comboBox->addItem(list[i].portName() + "," + list[i].manufacturer()/* + "," + list[i].description() + "," + QString::number(list[i].productIdentifier())*/);
    }
    bico_port_list_comboBox->setCurrentIndex(0);

    get_serial_data_timer = new QTimer(this);
    get_serial_data_timer->setInterval(1);
    get_serial_data_timer_connection = connect(get_serial_data_timer, SIGNAL(timeout()), this, SLOT(update_serial_data_to_plaint_text()));
}

void ESP_Wifi_Config_Window::devDestroy()
{
    disconnect(get_serial_data_timer_connection);
}

void ESP_Wifi_Config_Window::JsonObjectToPlaintText(QJsonObject json_object)
{
    QJsonDocument json_doc(json_object);
    com_port_manager->print(QString(json_doc.toJson()));

    ui->configuration_data_plainTextEdit->setPlainText(QString(json_doc.toJson()));
}


void ESP_Wifi_Config_Window::update_serial_data_to_plaint_text()
{
    if(com_port_manager->available() > 0)
    {
        ui->data_from_com_port_plainTextEdit->insertPlainText(QString(com_port_manager->readString()));
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










ESP_Wifi_Config_Window::ESP_Wifi_Config_Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ESP_Wifi_Config_Window)
{
    ui->setupUi(this);
    devConstruct();
}

ESP_Wifi_Config_Window::~ESP_Wifi_Config_Window()
{
    devDestroy();
    delete ui;
}











void ESP_Wifi_Config_Window::on_file_load_pushButton_clicked()
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


void ESP_Wifi_Config_Window::on_file_save_pushButton_clicked()
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


void ESP_Wifi_Config_Window::on_connect_pushButton_clicked()
{
   if(com_port_manager->begin(bico_port_list_comboBox->currentText().section(',', 0, 0), ui->baudrate_comboBox->currentText().toLong()))
   {
       ui->connect_state_label->setText("Connected");
       get_serial_data_timer->start();
   }
}


void ESP_Wifi_Config_Window::on_close_pushButton_clicked()
{
    com_port_manager->end();
    ui->connect_state_label->setText("Disconnected");
    get_serial_data_timer->stop();
}


void ESP_Wifi_Config_Window::on_basic_setting_to_text_clicked()
{
        QJsonObject temp_json_obj;
        (temp_json_obj)[BC_SWFS_COMMAND] = SETTING_WIFI_CONFIG;
        (temp_json_obj)["_host_ssid"] = ui->ssid_lineEdit->text();
        (temp_json_obj)["_host_password"] = ui->password_lineEdit->text();
        (temp_json_obj)["_ip"] = ui->static_ip_lineEdit->text();
        (temp_json_obj)["_gateway"] = ui->gateway_lineEdit->text();
        (temp_json_obj)["_subnet"] = ui->subnet_lineEdit->text();
        (temp_json_obj)["_dhcp_enable"] = uint8_t(ui->dhcp_enable_checkBox->isChecked());
        (temp_json_obj)["_connect_timeout"] = ui->connection_timeout_lineEdit->text().toInt();

        JsonObjectToPlaintText(temp_json_obj);
}


void ESP_Wifi_Config_Window::on_text_to_basic_setting_clicked()
{
    QJsonDocument json_doc = QJsonDocument::fromJson(ui->configuration_data_plainTextEdit->toPlainText().toUtf8());
    if(!json_doc.isNull())
    {
        QJsonObject json_obj = json_doc.object();

        if(json_obj.contains("_host_ssid"))
        {
            ui->ssid_lineEdit->setText(json_obj["_host_ssid"].toString());
        }


        if(json_obj.contains("_host_password"))
        {
            ui->password_lineEdit->setText(json_obj["_host_password"].toString());
        }

        if(json_obj.contains("_ip"))
        {
            ui->static_ip_lineEdit->setText(json_obj["_ip"].toString());
        }

        if(json_obj.contains("_gateway"))
        {
            ui->gateway_lineEdit->setText(json_obj["_gateway"].toString());
        }

        if(json_obj.contains("_subnet"))
        {
            ui->subnet_lineEdit->setText(json_obj["_subnet"].toString());
        }

        if(json_obj.contains("_dhcp_enable"))
        {
            ui->dhcp_enable_checkBox->setChecked(!!(json_obj["_dhcp_enable"].toInt()));
        }

        if(json_obj.contains("_connect_timeout"))
        {
            ui->connection_timeout_lineEdit->setText(QString::number(json_obj["_connect_timeout"].toInt()));
        }
    }
    else
    {
        QMessageBox::information(Q_NULLPTR, "Info", "Invalid JSON");
    }
}


void ESP_Wifi_Config_Window::on_dhcp_enable_checkBox_stateChanged(int arg1)
{
    ui->static_ip_lineEdit->setEnabled(!bool(arg1));
    ui->static_ip_pushButton->setEnabled(!bool(arg1));
    ui->gateway_lineEdit->setEnabled(!bool(arg1));
    ui->gateway_pushButton->setEnabled(!bool(arg1));
    ui->subnet_lineEdit->setEnabled(!bool(arg1));
    ui->subnet_pushButton->setEnabled(!bool(arg1));
}

void ESP_Wifi_Config_Window::on_ssid_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_SWFS_COMMAND] = SETTING_WIFI_CONFIG;
    (temp_json_obj)["_host_ssid"] = ui->ssid_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_Wifi_Config_Window::on_password_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_SWFS_COMMAND] = SETTING_WIFI_CONFIG;
    (temp_json_obj)["_host_password"] = ui->password_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_Wifi_Config_Window::on_dhcp_enable_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_SWFS_COMMAND] = SETTING_WIFI_CONFIG;
    (temp_json_obj)["_dhcp_enable"] = uint8_t(ui->dhcp_enable_checkBox->isChecked());

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_Wifi_Config_Window::on_static_ip_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_SWFS_COMMAND] = SETTING_WIFI_CONFIG;
    (temp_json_obj)["_ip"] = ui->static_ip_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_Wifi_Config_Window::on_gateway_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_SWFS_COMMAND] = SETTING_WIFI_CONFIG;
    (temp_json_obj)["_gateway"] = ui->gateway_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_Wifi_Config_Window::on_subnet_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_SWFS_COMMAND] = SETTING_WIFI_CONFIG;
    (temp_json_obj)["_subnet"] = ui->subnet_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_Wifi_Config_Window::on_connection_timeout_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_SWFS_COMMAND] = SETTING_WIFI_CONFIG;
    (temp_json_obj)["_connect_timeout"] = ui->connection_timeout_lineEdit->text();

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_Wifi_Config_Window::on_submit_all_pushButton_clicked()
{
    com_port_manager->print(ui->configuration_data_plainTextEdit->toPlainText().toUtf8());
}

void ESP_Wifi_Config_Window::on_get_properties_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_SWFS_COMMAND] = BC_SWFS_GET_PROPERTIES;

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_Wifi_Config_Window::on_wifi_connect_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_SWFS_COMMAND] = WIFI_CONNECT;

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_Wifi_Config_Window::on_wifi_disconnect_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_SWFS_COMMAND] = WIFI_DISCONNECT;

    JsonObjectToPlaintText(temp_json_obj);
}

void ESP_Wifi_Config_Window::on_device_reboot_pushButton_clicked()
{
    QJsonObject temp_json_obj;
    (temp_json_obj)[BC_SWFS_COMMAND] = BC_SWFS_DEVICE_REBOOT;

    JsonObjectToPlaintText(temp_json_obj);
}
