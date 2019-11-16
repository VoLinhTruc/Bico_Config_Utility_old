/********************************************************************************
** Form generated from reading UI file 'esp_mqtt_config_window.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESP_MQTT_CONFIG_WINDOW_H
#define UI_ESP_MQTT_CONFIG_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ESP_MQTT_Config_Window
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_16;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_6;
    QLabel *label_9;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_14;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_9;
    QPushButton *pushButton_2;
    QLabel *label_8;
    QLabel *label_6;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_8;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_9;
    QLabel *label_11;
    QCheckBox *checkBox_5;
    QLabel *label_10;
    QCheckBox *checkBox;
    QLabel *label_7;
    QLabel *label;
    QPushButton *pushButton_15;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_4;
    QLabel *label_5;
    QCheckBox *checkBox_4;
    QLabel *label_3;
    QCheckBox *checkBox_9;
    QWidget *tab_2;
    QLineEdit *lineEdit_14;
    QPushButton *pushButton_19;
    QPushButton *pushButton_7;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_17;
    QPushButton *pushButton_17;
    QLabel *label_14;
    QLabel *label_12;
    QCheckBox *checkBox_7;
    QLabel *label_19;
    QLineEdit *lineEdit_11;
    QLabel *label_20;
    QLineEdit *lineEdit_13;
    QComboBox *comboBox_4;
    QPushButton *pushButton_12;
    QLineEdit *lineEdit_12;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_18;
    QPushButton *pushButton_11;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton_13;
    QPushButton *pushButton_20;
    QCheckBox *checkBox_8;
    QComboBox *comboBox_3;
    QComboBox *comboBox_5;
    QLabel *label_16;
    QPushButton *pushButton_10;
    QCheckBox *checkBox_6;
    QPushButton *pushButton_18;
    QCheckBox *checkBox_10;
    QWidget *tab_3;
    QLabel *file_path_lable;
    QPushButton *submit_all_pushButton;
    QPushButton *file_load_pushButton;
    QLineEdit *file_path_lineEdit;
    QPushButton *file_save_pushButton;
    QPlainTextEdit *configuration_data_plainTextEdit;
    QPushButton *basic_setting_to_text;
    QPushButton *text_to_basic_setting;
    QPlainTextEdit *data_from_co_port_plainTextEdit;
    QGroupBox *com_port_groupBox;
    QComboBox *port_list_comboBox;
    QComboBox *baudrate_comboBox;
    QLabel *port_label;
    QLabel *baudrate_label;
    QPushButton *connect_pushButton;
    QPushButton *close_pushButton;
    QLabel *connect_state_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ESP_MQTT_Config_Window)
    {
        if (ESP_MQTT_Config_Window->objectName().isEmpty())
            ESP_MQTT_Config_Window->setObjectName(QString::fromUtf8("ESP_MQTT_Config_Window"));
        ESP_MQTT_Config_Window->resize(861, 778);
        centralwidget = new QWidget(ESP_MQTT_Config_Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 471, 491));
        tabWidget->setAutoFillBackground(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        comboBox_2 = new QComboBox(tab);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(200, 420, 51, 22));
        lineEdit_6 = new QLineEdit(tab);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(100, 250, 151, 20));
        pushButton_16 = new QPushButton(tab);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(270, 340, 51, 23));
        pushButton_8 = new QPushButton(tab);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(270, 280, 51, 23));
        lineEdit_7 = new QLineEdit(tab);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(100, 310, 151, 20));
        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(270, 390, 51, 23));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 280, 71, 16));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(270, 120, 51, 23));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 61, 16));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 150, 71, 16));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(100, 120, 151, 20));
        checkBox_3 = new QCheckBox(tab);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(20, 220, 91, 17));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(100, 150, 151, 20));
        pushButton_14 = new QPushButton(tab);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(270, 250, 51, 23));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 40, 151, 20));
        lineEdit_9 = new QLineEdit(tab);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(100, 280, 151, 20));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 70, 51, 23));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 340, 61, 16));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 250, 61, 16));
        comboBox = new QComboBox(tab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(200, 200, 51, 22));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 40, 51, 23));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 70, 151, 20));
        lineEdit_8 = new QLineEdit(tab);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(100, 340, 151, 20));
        checkBox_2 = new QCheckBox(tab);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(130, 180, 70, 17));
        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(270, 150, 51, 23));
        pushButton_9 = new QPushButton(tab);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(270, 190, 51, 41));
        label_11 = new QLabel(tab);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 420, 61, 16));
        checkBox_5 = new QCheckBox(tab);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(130, 220, 70, 17));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(150, 200, 51, 16));
        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(20, 180, 91, 17));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 310, 61, 16));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 61, 16));
        pushButton_15 = new QPushButton(tab);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setGeometry(QRect(270, 310, 51, 23));
        lineEdit_5 = new QLineEdit(tab);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(100, 390, 151, 20));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(270, 420, 51, 23));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 390, 61, 16));
        checkBox_4 = new QCheckBox(tab);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(20, 200, 91, 17));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 120, 71, 16));
        checkBox_9 = new QCheckBox(tab);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setGeometry(QRect(20, 10, 101, 17));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        lineEdit_14 = new QLineEdit(tab_2);
        lineEdit_14->setObjectName(QString::fromUtf8("lineEdit_14"));
        lineEdit_14->setGeometry(QRect(180, 420, 71, 20));
        pushButton_19 = new QPushButton(tab_2);
        pushButton_19->setObjectName(QString::fromUtf8("pushButton_19"));
        pushButton_19->setGeometry(QRect(270, 420, 51, 23));
        pushButton_7 = new QPushButton(tab_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(270, 40, 51, 31));
        plainTextEdit = new QPlainTextEdit(tab_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(100, 170, 151, 91));
        label_17 = new QLabel(tab_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(20, 350, 41, 31));
        pushButton_17 = new QPushButton(tab_2);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(270, 360, 51, 23));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 135, 71, 31));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(140, 40, 51, 16));
        checkBox_7 = new QCheckBox(tab_2);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(20, 40, 91, 17));
        label_19 = new QLabel(tab_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(20, 420, 81, 16));
        lineEdit_11 = new QLineEdit(tab_2);
        lineEdit_11->setObjectName(QString::fromUtf8("lineEdit_11"));
        lineEdit_11->setGeometry(QRect(100, 140, 151, 20));
        label_20 = new QLabel(tab_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(20, 200, 71, 31));
        lineEdit_13 = new QLineEdit(tab_2);
        lineEdit_13->setObjectName(QString::fromUtf8("lineEdit_13"));
        lineEdit_13->setGeometry(QRect(180, 390, 71, 20));
        comboBox_4 = new QComboBox(tab_2);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(180, 300, 71, 22));
        pushButton_12 = new QPushButton(tab_2);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(270, 300, 51, 23));
        lineEdit_12 = new QLineEdit(tab_2);
        lineEdit_12->setObjectName(QString::fromUtf8("lineEdit_12"));
        lineEdit_12->setGeometry(QRect(180, 330, 71, 20));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 110, 71, 16));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 300, 71, 16));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(20, 390, 71, 16));
        pushButton_11 = new QPushButton(tab_2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(270, 140, 51, 23));
        lineEdit_10 = new QLineEdit(tab_2);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(100, 110, 151, 20));
        pushButton_13 = new QPushButton(tab_2);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(270, 330, 51, 23));
        pushButton_20 = new QPushButton(tab_2);
        pushButton_20->setObjectName(QString::fromUtf8("pushButton_20"));
        pushButton_20->setGeometry(QRect(270, 170, 51, 91));
        checkBox_8 = new QCheckBox(tab_2);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setGeometry(QRect(80, 360, 51, 17));
        comboBox_3 = new QComboBox(tab_2);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(200, 40, 51, 22));
        comboBox_5 = new QComboBox(tab_2);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(140, 360, 111, 22));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(20, 320, 61, 31));
        pushButton_10 = new QPushButton(tab_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(270, 110, 51, 23));
        checkBox_6 = new QCheckBox(tab_2);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(20, 60, 70, 17));
        pushButton_18 = new QPushButton(tab_2);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setGeometry(QRect(270, 390, 51, 23));
        checkBox_10 = new QCheckBox(tab_2);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setGeometry(QRect(20, 10, 101, 17));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        file_path_lable = new QLabel(centralwidget);
        file_path_lable->setObjectName(QString::fromUtf8("file_path_lable"));
        file_path_lable->setGeometry(QRect(580, 30, 47, 13));
        submit_all_pushButton = new QPushButton(centralwidget);
        submit_all_pushButton->setObjectName(QString::fromUtf8("submit_all_pushButton"));
        submit_all_pushButton->setGeometry(QRect(530, 470, 291, 31));
        file_load_pushButton = new QPushButton(centralwidget);
        file_load_pushButton->setObjectName(QString::fromUtf8("file_load_pushButton"));
        file_load_pushButton->setGeometry(QRect(630, 60, 71, 23));
        file_path_lineEdit = new QLineEdit(centralwidget);
        file_path_lineEdit->setObjectName(QString::fromUtf8("file_path_lineEdit"));
        file_path_lineEdit->setGeometry(QRect(630, 30, 191, 20));
        file_save_pushButton = new QPushButton(centralwidget);
        file_save_pushButton->setObjectName(QString::fromUtf8("file_save_pushButton"));
        file_save_pushButton->setGeometry(QRect(750, 60, 71, 23));
        configuration_data_plainTextEdit = new QPlainTextEdit(centralwidget);
        configuration_data_plainTextEdit->setObjectName(QString::fromUtf8("configuration_data_plainTextEdit"));
        configuration_data_plainTextEdit->setGeometry(QRect(530, 110, 291, 351));
        basic_setting_to_text = new QPushButton(centralwidget);
        basic_setting_to_text->setObjectName(QString::fromUtf8("basic_setting_to_text"));
        basic_setting_to_text->setGeometry(QRect(490, 230, 31, 23));
        text_to_basic_setting = new QPushButton(centralwidget);
        text_to_basic_setting->setObjectName(QString::fromUtf8("text_to_basic_setting"));
        text_to_basic_setting->setGeometry(QRect(490, 260, 31, 23));
        data_from_co_port_plainTextEdit = new QPlainTextEdit(centralwidget);
        data_from_co_port_plainTextEdit->setObjectName(QString::fromUtf8("data_from_co_port_plainTextEdit"));
        data_from_co_port_plainTextEdit->setGeometry(QRect(530, 520, 291, 71));
        com_port_groupBox = new QGroupBox(centralwidget);
        com_port_groupBox->setObjectName(QString::fromUtf8("com_port_groupBox"));
        com_port_groupBox->setGeometry(QRect(10, 510, 471, 81));
        port_list_comboBox = new QComboBox(com_port_groupBox);
        port_list_comboBox->setObjectName(QString::fromUtf8("port_list_comboBox"));
        port_list_comboBox->setGeometry(QRect(20, 40, 231, 22));
        baudrate_comboBox = new QComboBox(com_port_groupBox);
        baudrate_comboBox->addItem(QString());
        baudrate_comboBox->addItem(QString());
        baudrate_comboBox->addItem(QString());
        baudrate_comboBox->addItem(QString());
        baudrate_comboBox->addItem(QString());
        baudrate_comboBox->addItem(QString());
        baudrate_comboBox->addItem(QString());
        baudrate_comboBox->addItem(QString());
        baudrate_comboBox->setObjectName(QString::fromUtf8("baudrate_comboBox"));
        baudrate_comboBox->setEnabled(true);
        baudrate_comboBox->setGeometry(QRect(260, 40, 71, 22));
        port_label = new QLabel(com_port_groupBox);
        port_label->setObjectName(QString::fromUtf8("port_label"));
        port_label->setGeometry(QRect(20, 20, 61, 16));
        baudrate_label = new QLabel(com_port_groupBox);
        baudrate_label->setObjectName(QString::fromUtf8("baudrate_label"));
        baudrate_label->setGeometry(QRect(260, 20, 71, 16));
        connect_pushButton = new QPushButton(com_port_groupBox);
        connect_pushButton->setObjectName(QString::fromUtf8("connect_pushButton"));
        connect_pushButton->setGeometry(QRect(350, 40, 51, 23));
        close_pushButton = new QPushButton(com_port_groupBox);
        close_pushButton->setObjectName(QString::fromUtf8("close_pushButton"));
        close_pushButton->setGeometry(QRect(410, 40, 51, 23));
        connect_state_label = new QLabel(com_port_groupBox);
        connect_state_label->setObjectName(QString::fromUtf8("connect_state_label"));
        connect_state_label->setGeometry(QRect(350, 20, 71, 16));
        ESP_MQTT_Config_Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ESP_MQTT_Config_Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 861, 21));
        ESP_MQTT_Config_Window->setMenuBar(menubar);
        statusbar = new QStatusBar(ESP_MQTT_Config_Window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ESP_MQTT_Config_Window->setStatusBar(statusbar);

        retranslateUi(ESP_MQTT_Config_Window);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ESP_MQTT_Config_Window);
    } // setupUi

    void retranslateUi(QMainWindow *ESP_MQTT_Config_Window)
    {
        ESP_MQTT_Config_Window->setWindowTitle(QCoreApplication::translate("ESP_MQTT_Config_Window", "MainWindow", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("ESP_MQTT_Config_Window", "0", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("ESP_MQTT_Config_Window", "1", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("ESP_MQTT_Config_Window", "2", nullptr));

        lineEdit_6->setText(QString());
        pushButton_16->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        pushButton_8->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        lineEdit_7->setText(QString());
        pushButton_6->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        label_9->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Will Message", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        label_2->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Broker Port", nullptr));
        label_4->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Protocol Level", nullptr));
        lineEdit_3->setText(QString());
        checkBox_3->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Password Flag", nullptr));
        lineEdit_4->setText(QString());
        pushButton_14->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        lineEdit_9->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        label_8->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Password", nullptr));
        label_6->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Will Topic", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("ESP_MQTT_Config_Window", "0", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("ESP_MQTT_Config_Window", "1", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("ESP_MQTT_Config_Window", "2", nullptr));

        pushButton->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_8->setText(QString());
        checkBox_2->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Will Flag", nullptr));
        pushButton_5->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        pushButton_9->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        label_11->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Max QoS", nullptr));
        checkBox_5->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "User Flag", nullptr));
        label_10->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Will QoS", nullptr));
        checkBox->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Clean Session", nullptr));
        label_7->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "User", nullptr));
        label->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Broker IP", nullptr));
        pushButton_15->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        pushButton_4->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        label_5->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Topic filter", nullptr));
        checkBox_4->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Will Retain", nullptr));
        label_3->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Protocol Name", nullptr));
        checkBox_9->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Minimize Setting", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("ESP_MQTT_Config_Window", "Start up Setting", nullptr));
        lineEdit_14->setText(QString());
        pushButton_19->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        pushButton_7->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        label_17->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Trigger\n"
"Type", nullptr));
        pushButton_17->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        label_14->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Application\n"
"Message", nullptr));
        label_12->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "QoS Level", nullptr));
        checkBox_7->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "RETAIN", nullptr));
        label_19->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Uart Trigge Sign", nullptr));
        lineEdit_11->setText(QString());
        label_20->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Application\n"
"Field", nullptr));
        lineEdit_13->setText(QString());
        comboBox_4->setItemText(0, QCoreApplication::translate("ESP_MQTT_Config_Window", "Continous", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("ESP_MQTT_Config_Window", "Trigger", nullptr));

        pushButton_12->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        label_13->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Topic Name", nullptr));
        label_15->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Publish Mode", nullptr));
        label_18->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Triger Pin", nullptr));
        pushButton_11->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        lineEdit_10->setText(QString());
        pushButton_13->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        pushButton_20->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        checkBox_8->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Uart +", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("ESP_MQTT_Config_Window", "0", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("ESP_MQTT_Config_Window", "1", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("ESP_MQTT_Config_Window", "2", nullptr));

        comboBox_5->setItemText(0, QCoreApplication::translate("ESP_MQTT_Config_Window", "Raising or Falling", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("ESP_MQTT_Config_Window", "Raising", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("ESP_MQTT_Config_Window", "Falling", nullptr));
        comboBox_5->setItemText(3, QCoreApplication::translate("ESP_MQTT_Config_Window", "Uart", nullptr));

        label_16->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Continous\n"
"Interval (ms)", nullptr));
        pushButton_10->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        checkBox_6->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "DUP Flag", nullptr));
        pushButton_18->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit", nullptr));
        checkBox_10->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Minimize Setting", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("ESP_MQTT_Config_Window", "Publish Setting", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("ESP_MQTT_Config_Window", "On Received Setting", nullptr));
        file_path_lable->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "File Path", nullptr));
        submit_all_pushButton->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Submit All", nullptr));
        file_load_pushButton->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Load", nullptr));
        file_save_pushButton->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Save", nullptr));
        basic_setting_to_text->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "->", nullptr));
        text_to_basic_setting->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "<-", nullptr));
        com_port_groupBox->setTitle(QCoreApplication::translate("ESP_MQTT_Config_Window", "COM Port", nullptr));
        baudrate_comboBox->setItemText(0, QCoreApplication::translate("ESP_MQTT_Config_Window", "9600", nullptr));
        baudrate_comboBox->setItemText(1, QCoreApplication::translate("ESP_MQTT_Config_Window", "115200", nullptr));
        baudrate_comboBox->setItemText(2, QCoreApplication::translate("ESP_MQTT_Config_Window", "38400", nullptr));
        baudrate_comboBox->setItemText(3, QCoreApplication::translate("ESP_MQTT_Config_Window", "57600", nullptr));
        baudrate_comboBox->setItemText(4, QCoreApplication::translate("ESP_MQTT_Config_Window", "1200", nullptr));
        baudrate_comboBox->setItemText(5, QCoreApplication::translate("ESP_MQTT_Config_Window", "2400", nullptr));
        baudrate_comboBox->setItemText(6, QCoreApplication::translate("ESP_MQTT_Config_Window", "4800", nullptr));
        baudrate_comboBox->setItemText(7, QCoreApplication::translate("ESP_MQTT_Config_Window", "19200", nullptr));

        port_label->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Port", nullptr));
        baudrate_label->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "BaudRate", nullptr));
        connect_pushButton->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Connect", nullptr));
        close_pushButton->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Close", nullptr));
        connect_state_label->setText(QCoreApplication::translate("ESP_MQTT_Config_Window", "Disconnected", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ESP_MQTT_Config_Window: public Ui_ESP_MQTT_Config_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESP_MQTT_CONFIG_WINDOW_H
