#ifndef COM_PORT_MANAGER_H
#define COM_PORT_MANAGER_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>
#include <QMessageBox>

typedef enum
{
    CONNECTING,
    IDLE
}
Com_Port_State;

class Com_Port_Manager : QObject
{
public:
    Com_Port_Manager(QObject *parent = nullptr);
    ~Com_Port_Manager();

    uint8_t begin(QString port_name, qint32 baudrate);
    void end();

    qint64 available();
    char read();
    QString readString();
    void write(char data);
    qint64 print(QString string);

private:
    QSerialPort *com_port_obj;
    Com_Port_State *com_port_state;
};

#endif // COM_PORT_MANAGER_H
