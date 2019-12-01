#include "com_port_manager.h"

Com_Port_Manager::Com_Port_Manager(QObject *parent) :
    QObject(parent)
{
    com_port_obj = new QSerialPort;
    com_port_state = new Com_Port_State;
    *com_port_state = IDLE;
}

Com_Port_Manager::~Com_Port_Manager()
{
    delete com_port_obj;
}

uint8_t Com_Port_Manager::begin(QString port_name, qint32 baudrate)
{
    if(*com_port_state == IDLE)
    {
        com_port_obj->setPortName(port_name);
        com_port_obj->setBaudRate(baudrate);
        com_port_obj->setDataBits(QSerialPort::Data8);
        com_port_obj->setParity(QSerialPort::NoParity);
        com_port_obj->setStopBits(QSerialPort::OneStop);
        com_port_obj->setFlowControl(QSerialPort::NoFlowControl);

        if(!com_port_obj->open(QIODevice::ReadWrite))
        {
            QMessageBox::information(Q_NULLPTR, "Info", com_port_obj->errorString());
            return 0;
        }
        else
        {
            *com_port_state = CONNECTING;
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

void Com_Port_Manager::end()
{
    if(*com_port_state == CONNECTING)
    {
        com_port_obj->close();
        *com_port_state = IDLE;
    }
}

qint64 Com_Port_Manager::available()
{
    if(*com_port_state == CONNECTING)
    {
        return com_port_obj->bytesAvailable();
    }
    else
    {
        return -1;
    }
}

char Com_Port_Manager::read()
{
    if(*com_port_state == CONNECTING)
    {
        char temp_data;
        com_port_obj->read(&temp_data, 1);

        return temp_data;
    }
    else
    {
        return -1;
    }
}

QString Com_Port_Manager::readString()
{
    if(*com_port_state == CONNECTING)
    {
        QString result = "";
        while(available() > 0)
        {
            result += QString(read());
        }

        return result;
    }
    else
    {
        return QString("");
    }
}

void Com_Port_Manager::write(char data)
{
    if(*com_port_state == CONNECTING)
    {
        com_port_obj->write(&data, 1);
    }
}

qint64 Com_Port_Manager::print(QString string)
{
    if(*com_port_state == CONNECTING)
    {
        return com_port_obj->write(string.toLocal8Bit());
    }
    else
    {
        return -1;
    }
}
