#ifndef AVAILABLE_COM_PORT_COMBOBOX_H
#define AVAILABLE_COM_PORT_COMBOBOX_H

#include <QSerialPortInfo>
#include <QComboBox>
#include <QMessageBox>
#include <QList>

class Available_Com_Port_ComboBox : public QComboBox
{
    Q_OBJECT
public:
    Available_Com_Port_ComboBox(QComboBox *occupied_ui);
    ~Available_Com_Port_ComboBox();

    virtual void showPopup();

public slots:
    void updateItemList();

signals:
    void clicked();
};

#endif // AVAILABLE_COM_PORT_COMBOBOX_H
