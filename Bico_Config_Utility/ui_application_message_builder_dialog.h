/********************************************************************************
** Form generated from reading UI file 'application_message_builder_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATION_MESSAGE_BUILDER_DIALOG_H
#define UI_APPLICATION_MESSAGE_BUILDER_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Application_message_Builder_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QPlainTextEdit *result_string_plainTextEdit;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *digital_read_pushButton;
    QPushButton *analog_read_pushButton;
    QPushButton *digital_read_gpio16_pushButton;
    QPushButton *digital_read_gpio5_pushButton;
    QPushButton *digital_read_gpio4_pushButton;
    QPushButton *digital_read_gpio14_pushButton;
    QPushButton *digital_read_gpio2_pushButton;
    QPushButton *digital_read_gpio0_pushButton;
    QPushButton *digital_read_gpio15_pushButton;
    QPushButton *digital_read_gpio13_pushButton;
    QPushButton *digital_read_gpio12_pushButton;
    QPushButton *analog_read_A0_pushButton;
    QWidget *tab_4;

    void setupUi(QDialog *Application_message_Builder_Dialog)
    {
        if (Application_message_Builder_Dialog->objectName().isEmpty())
            Application_message_Builder_Dialog->setObjectName(QString::fromUtf8("Application_message_Builder_Dialog"));
        Application_message_Builder_Dialog->resize(474, 406);
        buttonBox = new QDialogButtonBox(Application_message_Builder_Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(160, 370, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        result_string_plainTextEdit = new QPlainTextEdit(Application_message_Builder_Dialog);
        result_string_plainTextEdit->setObjectName(QString::fromUtf8("result_string_plainTextEdit"));
        result_string_plainTextEdit->setGeometry(QRect(10, 40, 231, 321));
        tabWidget = new QTabWidget(Application_message_Builder_Dialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(260, 10, 201, 351));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        digital_read_pushButton = new QPushButton(tab);
        digital_read_pushButton->setObjectName(QString::fromUtf8("digital_read_pushButton"));
        digital_read_pushButton->setGeometry(QRect(10, 10, 75, 23));
        analog_read_pushButton = new QPushButton(tab);
        analog_read_pushButton->setObjectName(QString::fromUtf8("analog_read_pushButton"));
        analog_read_pushButton->setGeometry(QRect(110, 10, 75, 23));
        digital_read_gpio16_pushButton = new QPushButton(tab);
        digital_read_gpio16_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio16_pushButton"));
        digital_read_gpio16_pushButton->setEnabled(false);
        digital_read_gpio16_pushButton->setGeometry(QRect(20, 50, 51, 23));
        digital_read_gpio5_pushButton = new QPushButton(tab);
        digital_read_gpio5_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio5_pushButton"));
        digital_read_gpio5_pushButton->setEnabled(false);
        digital_read_gpio5_pushButton->setGeometry(QRect(20, 80, 51, 23));
        digital_read_gpio4_pushButton = new QPushButton(tab);
        digital_read_gpio4_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio4_pushButton"));
        digital_read_gpio4_pushButton->setEnabled(false);
        digital_read_gpio4_pushButton->setGeometry(QRect(20, 110, 51, 23));
        digital_read_gpio14_pushButton = new QPushButton(tab);
        digital_read_gpio14_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio14_pushButton"));
        digital_read_gpio14_pushButton->setEnabled(false);
        digital_read_gpio14_pushButton->setGeometry(QRect(20, 200, 51, 23));
        digital_read_gpio2_pushButton = new QPushButton(tab);
        digital_read_gpio2_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio2_pushButton"));
        digital_read_gpio2_pushButton->setEnabled(false);
        digital_read_gpio2_pushButton->setGeometry(QRect(20, 170, 51, 23));
        digital_read_gpio0_pushButton = new QPushButton(tab);
        digital_read_gpio0_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio0_pushButton"));
        digital_read_gpio0_pushButton->setEnabled(false);
        digital_read_gpio0_pushButton->setGeometry(QRect(20, 140, 51, 23));
        digital_read_gpio15_pushButton = new QPushButton(tab);
        digital_read_gpio15_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio15_pushButton"));
        digital_read_gpio15_pushButton->setEnabled(false);
        digital_read_gpio15_pushButton->setGeometry(QRect(20, 290, 51, 23));
        digital_read_gpio13_pushButton = new QPushButton(tab);
        digital_read_gpio13_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio13_pushButton"));
        digital_read_gpio13_pushButton->setEnabled(false);
        digital_read_gpio13_pushButton->setGeometry(QRect(20, 260, 51, 23));
        digital_read_gpio12_pushButton = new QPushButton(tab);
        digital_read_gpio12_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio12_pushButton"));
        digital_read_gpio12_pushButton->setEnabled(false);
        digital_read_gpio12_pushButton->setGeometry(QRect(20, 230, 51, 23));
        analog_read_A0_pushButton = new QPushButton(tab);
        analog_read_A0_pushButton->setObjectName(QString::fromUtf8("analog_read_A0_pushButton"));
        analog_read_A0_pushButton->setEnabled(false);
        analog_read_A0_pushButton->setGeometry(QRect(120, 50, 51, 23));
        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());

        retranslateUi(Application_message_Builder_Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Application_message_Builder_Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Application_message_Builder_Dialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Application_message_Builder_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Application_message_Builder_Dialog)
    {
        Application_message_Builder_Dialog->setWindowTitle(QCoreApplication::translate("Application_message_Builder_Dialog", "Dialog", nullptr));
        digital_read_pushButton->setText(QCoreApplication::translate("Application_message_Builder_Dialog", "Digital Read", nullptr));
        analog_read_pushButton->setText(QCoreApplication::translate("Application_message_Builder_Dialog", "Analog Read", nullptr));
        digital_read_gpio16_pushButton->setText(QCoreApplication::translate("Application_message_Builder_Dialog", "GPIO16", nullptr));
        digital_read_gpio5_pushButton->setText(QCoreApplication::translate("Application_message_Builder_Dialog", "GPIO5", nullptr));
        digital_read_gpio4_pushButton->setText(QCoreApplication::translate("Application_message_Builder_Dialog", "GPIO4", nullptr));
        digital_read_gpio14_pushButton->setText(QCoreApplication::translate("Application_message_Builder_Dialog", "GPIO14", nullptr));
        digital_read_gpio2_pushButton->setText(QCoreApplication::translate("Application_message_Builder_Dialog", "GPIO2", nullptr));
        digital_read_gpio0_pushButton->setText(QCoreApplication::translate("Application_message_Builder_Dialog", "GPIO0", nullptr));
        digital_read_gpio15_pushButton->setText(QCoreApplication::translate("Application_message_Builder_Dialog", "GPIO15", nullptr));
        digital_read_gpio13_pushButton->setText(QCoreApplication::translate("Application_message_Builder_Dialog", "GPIO13", nullptr));
        digital_read_gpio12_pushButton->setText(QCoreApplication::translate("Application_message_Builder_Dialog", "GPIO12", nullptr));
        analog_read_A0_pushButton->setText(QCoreApplication::translate("Application_message_Builder_Dialog", "A0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Application_message_Builder_Dialog", "General", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Application_message_Builder_Dialog", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Application_message_Builder_Dialog: public Ui_Application_message_Builder_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATION_MESSAGE_BUILDER_DIALOG_H
