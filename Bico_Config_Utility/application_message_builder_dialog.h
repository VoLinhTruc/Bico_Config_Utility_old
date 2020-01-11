#ifndef APPLICATION_MESSAGE_BUILDER_DIALOG_H
#define APPLICATION_MESSAGE_BUILDER_DIALOG_H

#include <QDialog>

#define APPLICATION_MESSAGE_COMMAND_TAG "<cmd>"
#define APPLICATION_MESSAGE_COMMAND_END_TAG "</cmd>"
#define APPLICATION_MESSAGE_COMMAND_PIN_TAG "<pin>"
#define APPLICATION_MESSAGE_COMMAND_PIN_END_TAG "</pin>"
#define APPLICATION_MESSAGE_COMMAND_VALUE_TAG "<val>"
#define APPLICATION_MESSAGE_COMMAND_VALUE_END_TAG "</val>"
#define DIGITAL_READ_COMMAND "DIGITAL_READ_COMMAND"
#define ANALOG_READ_COMMAND "ANALOG_READ_COMMAND"
#define DIGITAL_WRITE_COMMAND "DIGITAL_WRITE_COMMAND"
#define ANALOG_WRITE_COMMAND "ANALOG_WRITE_COMMAND"


namespace Ui {
class Application_message_Builder_Dialog;
}

class Application_message_Builder_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Application_message_Builder_Dialog(QWidget *parent = nullptr);
    ~Application_message_Builder_Dialog();

private:
    Ui::Application_message_Builder_Dialog *ui;


//Dev's Properties------------------------------------------------------
// Attributes --------------------------
public:

private:
// Attributes --------------------------


// Methods --------------------------
public:
    QString getResult();

private:
    void devConstruct();
    void devDestroy();

    void setPushButtonEnable(bool digital_read, bool digital_pin, bool analog_read, bool analog_pin);
// Methods --------------------------
//Dev's Properties------------------------------------------------------

private slots:
    void on_digital_read_pushButton_clicked();

    void on_analog_read_pushButton_clicked();

    void on_digital_read_gpio16_pushButton_clicked();

    void on_digital_read_gpio5_pushButton_clicked();

    void on_digital_read_gpio4_pushButton_clicked();

    void on_digital_read_gpio0_pushButton_clicked();

    void on_digital_read_gpio2_pushButton_clicked();

    void on_digital_read_gpio14_pushButton_clicked();

    void on_digital_read_gpio12_pushButton_clicked();

    void on_digital_read_gpio13_pushButton_clicked();

    void on_digital_read_gpio15_pushButton_clicked();

    void on_analog_read_A0_pushButton_clicked();

    void on_Application_message_Builder_Dialog_accepted();


};

#endif // APPLICATION_MESSAGE_BUILDER_DIALOG_H
