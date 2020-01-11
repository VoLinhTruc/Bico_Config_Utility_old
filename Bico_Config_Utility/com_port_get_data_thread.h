#ifndef COM_PORT_GET_DATA_THREAD_H
#define COM_PORT_GET_DATA_THREAD_H

#include <QThread>
#include "com_port_manager.h"
#include "QPlainTextEdit"

class Com_Port_Get_Data_Thread : public QThread
{
    Q_OBJECT

public:
    Com_Port_Get_Data_Thread(QObject * parent = nullptr);

protected:
    void run(Com_Port_Manager* com_port, QPlainTextEdit* received_plaint_text);
};

#endif // COM_PORT_GET_DATA_THREAD_H
