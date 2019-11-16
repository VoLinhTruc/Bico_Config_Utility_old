#include "com_port_get_data_thread.h"

Com_Port_Get_Data_Thread::Com_Port_Get_Data_Thread(QObject * parent):
    QThread(parent)
{

}

void Com_Port_Get_Data_Thread::run(Com_Port_Manager* com_port, QPlainTextEdit* received_plaint_text)
{
    if(com_port->available() > 0)
    {
        received_plaint_text->setPlainText(received_plaint_text->toPlainText() + QString(com_port->read()));
    }
}
