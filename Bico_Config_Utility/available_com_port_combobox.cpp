#include "available_com_port_combobox.h"

Available_Com_Port_ComboBox::Available_Com_Port_ComboBox(QComboBox *occupied_ui) :
    QComboBox((QWidget*)(occupied_ui->parent()))
{
    setObjectName(occupied_ui->objectName());
    setGeometry(occupied_ui->geometry());
    occupied_ui->hide();
    connect(this, SIGNAL(clicked()), this, SLOT(updateItemList()));
}

Available_Com_Port_ComboBox::~Available_Com_Port_ComboBox()
{
    disconnect(this, SIGNAL(clicked()), this, SLOT(updateItemList()));
}

void Available_Com_Port_ComboBox::showPopup()
{
    emit clicked();
    QComboBox::showPopup();
}

void Available_Com_Port_ComboBox::updateItemList()
{
    QList<QSerialPortInfo> list = QSerialPortInfo::availablePorts();

    while(count() > 0)
    {
        removeItem(count()-1);
    }

    for(int i = 0; i < list.size(); i++)
    {
        addItem(list[i].portName() + "," + list[i].manufacturer()/* + "," + list[i].description() + "," + QString::number(list[i].productIdentifier())*/);
    }
}
