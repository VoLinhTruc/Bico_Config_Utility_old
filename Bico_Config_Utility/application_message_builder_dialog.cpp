#include "application_message_builder_dialog.h"
#include "ui_application_message_builder_dialog.h"

#include <QMessageBox>


//Dev's defination ----------------------------------------------------------------------------------------
void Application_message_Builder_Dialog::devConstruct()
{

}

void Application_message_Builder_Dialog::devDestroy()
{

}


void Application_message_Builder_Dialog::setPushButtonEnable(bool digital_read, bool digital_pin, bool analog_read, bool analog_pin)
{
    ui->digital_read_pushButton->setEnabled(digital_read);

    ui->digital_read_gpio16_pushButton->setEnabled(digital_pin);
    ui->digital_read_gpio5_pushButton->setEnabled(digital_pin);
    ui->digital_read_gpio4_pushButton->setEnabled(digital_pin);
    ui->digital_read_gpio0_pushButton->setEnabled(digital_pin);
    ui->digital_read_gpio2_pushButton->setEnabled(digital_pin);
    ui->digital_read_gpio14_pushButton->setEnabled(digital_pin);
    ui->digital_read_gpio12_pushButton->setEnabled(digital_pin);
    ui->digital_read_gpio13_pushButton->setEnabled(digital_pin);
    ui->digital_read_gpio15_pushButton->setEnabled(digital_pin);

    ui->analog_read_pushButton->setEnabled(analog_read);

    ui->analog_read_A0_pushButton->setEnabled(analog_pin);
}

QString Application_message_Builder_Dialog::getResult()
{
    QString result = QString(ui->result_string_plainTextEdit->toPlainText());
    return result;
}

//Dev's defination ----------------------------------------------------------------------------------------



Application_message_Builder_Dialog::Application_message_Builder_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Application_message_Builder_Dialog)
{
    ui->setupUi(this);
    devConstruct();
}

Application_message_Builder_Dialog::~Application_message_Builder_Dialog()
{
    delete ui;
    devDestroy();
}

void Application_message_Builder_Dialog::on_digital_read_pushButton_clicked()
{
    setPushButtonEnable(false, true, false, false);

    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_TAG);
    ui->result_string_plainTextEdit->insertPlainText(DIGITAL_READ_COMMAND);
    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_END_TAG);
}

void Application_message_Builder_Dialog::on_analog_read_pushButton_clicked()
{
    setPushButtonEnable(false, false, false, true);

    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_TAG);
    ui->result_string_plainTextEdit->insertPlainText(ANALOG_READ_COMMAND);
    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_END_TAG);
}

void Application_message_Builder_Dialog::on_digital_read_gpio16_pushButton_clicked()
{
    setPushButtonEnable(true, false, true, false);

    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_TAG);
    ui->result_string_plainTextEdit->insertPlainText("16");
    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_END_TAG);
}

void Application_message_Builder_Dialog::on_digital_read_gpio5_pushButton_clicked()
{
    setPushButtonEnable(true, false, true, false);

    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_TAG);
    ui->result_string_plainTextEdit->insertPlainText("5");
    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_END_TAG);
}

void Application_message_Builder_Dialog::on_digital_read_gpio4_pushButton_clicked()
{
    setPushButtonEnable(true, false, true, false);

    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_TAG);
    ui->result_string_plainTextEdit->insertPlainText("4");
    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_END_TAG);
}

void Application_message_Builder_Dialog::on_digital_read_gpio0_pushButton_clicked()
{
    setPushButtonEnable(true, false, true, false);

    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_TAG);
    ui->result_string_plainTextEdit->insertPlainText("0");
    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_END_TAG);
}

void Application_message_Builder_Dialog::on_digital_read_gpio2_pushButton_clicked()
{
    setPushButtonEnable(true, false, true, false);

    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_TAG);
    ui->result_string_plainTextEdit->insertPlainText("2");
    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_END_TAG);
}

void Application_message_Builder_Dialog::on_digital_read_gpio14_pushButton_clicked()
{
    setPushButtonEnable(true, false, true, false);

    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_TAG);
    ui->result_string_plainTextEdit->insertPlainText("14");
    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_END_TAG);
}

void Application_message_Builder_Dialog::on_digital_read_gpio12_pushButton_clicked()
{
    setPushButtonEnable(true, false, true, false);
    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_TAG);
    ui->result_string_plainTextEdit->insertPlainText("12");
    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_END_TAG);
}

void Application_message_Builder_Dialog::on_digital_read_gpio13_pushButton_clicked()
{
    setPushButtonEnable(true, false, true, false);

    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_TAG);
    ui->result_string_plainTextEdit->insertPlainText("13");
    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_END_TAG);
}

void Application_message_Builder_Dialog::on_digital_read_gpio15_pushButton_clicked()
{
    setPushButtonEnable(true, false, true, false);

    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_TAG);
    ui->result_string_plainTextEdit->insertPlainText("15");
    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_END_TAG);
}

void Application_message_Builder_Dialog::on_analog_read_A0_pushButton_clicked()
{
    setPushButtonEnable(true, false, true, false);

    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_TAG);
    ui->result_string_plainTextEdit->insertPlainText(QString("\"A0\""));
    ui->result_string_plainTextEdit->insertPlainText(APPLICATION_MESSAGE_COMMAND_PIN_END_TAG);
}

void Application_message_Builder_Dialog::on_Application_message_Builder_Dialog_accepted()
{
    //QMessageBox::information(Q_NULLPTR, "Info", ui->result_string_plainTextEdit->toPlainText());
}
