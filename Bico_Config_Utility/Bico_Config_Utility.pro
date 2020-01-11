#-------------------------------------------------
#
# Project created by QtCreator 2019-11-01T23:47:47
#
#-------------------------------------------------

QT       += core gui
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Bico_Config_Utility
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        application_message_builder_dialog.cpp \
        available_com_port_combobox.cpp \
        com_port_get_data_thread.cpp \
        com_port_manager.cpp \
        esp_mqtt_config_window.cpp \
        esp_wifi_config_window.cpp \
        main.cpp \
        mainwindow.cpp \
        wifi_station_setting_manager.cpp

HEADERS += \
        application_message_builder_dialog.h \
        available_com_port_combobox.h \
        com_port_get_data_thread.h \
        com_port_manager.h \
        esp_mqtt_config_window.h \
        esp_wifi_config_window.h \
        mainwindow.h \
        wifi_station_setting_manager.h

FORMS += \
        application_message_builder_dialog.ui \
        esp_mqtt_config_window.ui \
        esp_wifi_config_window.ui \
        mainwindow.ui

`
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
