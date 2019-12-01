/********************************************************************************
** Form generated from reading UI file 'message_builder_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGE_BUILDER_DIALOG_H
#define UI_MESSAGE_BUILDER_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
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
    QWidget *tab_2;
    QPlainTextEdit *result_string_plainTextEdit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(485, 392);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(0, 360, 471, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(270, 10, 201, 351));
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
        digital_read_gpio16_pushButton->setGeometry(QRect(20, 50, 51, 23));
        digital_read_gpio5_pushButton = new QPushButton(tab);
        digital_read_gpio5_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio5_pushButton"));
        digital_read_gpio5_pushButton->setGeometry(QRect(20, 80, 51, 23));
        digital_read_gpio4_pushButton = new QPushButton(tab);
        digital_read_gpio4_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio4_pushButton"));
        digital_read_gpio4_pushButton->setGeometry(QRect(20, 110, 51, 23));
        digital_read_gpio14_pushButton = new QPushButton(tab);
        digital_read_gpio14_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio14_pushButton"));
        digital_read_gpio14_pushButton->setGeometry(QRect(20, 200, 51, 23));
        digital_read_gpio2_pushButton = new QPushButton(tab);
        digital_read_gpio2_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio2_pushButton"));
        digital_read_gpio2_pushButton->setGeometry(QRect(20, 170, 51, 23));
        digital_read_gpio0_pushButton = new QPushButton(tab);
        digital_read_gpio0_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio0_pushButton"));
        digital_read_gpio0_pushButton->setGeometry(QRect(20, 140, 51, 23));
        digital_read_gpio15_pushButton = new QPushButton(tab);
        digital_read_gpio15_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio15_pushButton"));
        digital_read_gpio15_pushButton->setGeometry(QRect(20, 290, 51, 23));
        digital_read_gpio13_pushButton = new QPushButton(tab);
        digital_read_gpio13_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio13_pushButton"));
        digital_read_gpio13_pushButton->setGeometry(QRect(20, 260, 51, 23));
        digital_read_gpio12_pushButton = new QPushButton(tab);
        digital_read_gpio12_pushButton->setObjectName(QString::fromUtf8("digital_read_gpio12_pushButton"));
        digital_read_gpio12_pushButton->setGeometry(QRect(20, 230, 51, 23));
        analog_read_A0_pushButton = new QPushButton(tab);
        analog_read_A0_pushButton->setObjectName(QString::fromUtf8("analog_read_A0_pushButton"));
        analog_read_A0_pushButton->setGeometry(QRect(120, 50, 51, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        result_string_plainTextEdit = new QPlainTextEdit(Dialog);
        result_string_plainTextEdit->setObjectName(QString::fromUtf8("result_string_plainTextEdit"));
        result_string_plainTextEdit->setGeometry(QRect(20, 40, 231, 321));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        digital_read_pushButton->setText(QCoreApplication::translate("Dialog", "Digital Read", nullptr));
        analog_read_pushButton->setText(QCoreApplication::translate("Dialog", "Analog Read", nullptr));
        digital_read_gpio16_pushButton->setText(QCoreApplication::translate("Dialog", "GPIO16", nullptr));
        digital_read_gpio5_pushButton->setText(QCoreApplication::translate("Dialog", "GPIO5", nullptr));
        digital_read_gpio4_pushButton->setText(QCoreApplication::translate("Dialog", "GPIO4", nullptr));
        digital_read_gpio14_pushButton->setText(QCoreApplication::translate("Dialog", "GPIO14", nullptr));
        digital_read_gpio2_pushButton->setText(QCoreApplication::translate("Dialog", "GPIO2", nullptr));
        digital_read_gpio0_pushButton->setText(QCoreApplication::translate("Dialog", "GPIO0", nullptr));
        digital_read_gpio15_pushButton->setText(QCoreApplication::translate("Dialog", "GPIO15", nullptr));
        digital_read_gpio13_pushButton->setText(QCoreApplication::translate("Dialog", "GPIO13", nullptr));
        digital_read_gpio12_pushButton->setText(QCoreApplication::translate("Dialog", "GPIO12", nullptr));
        analog_read_A0_pushButton->setText(QCoreApplication::translate("Dialog", "GPIO16", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Dialog", "General", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Dialog", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_BUILDER_DIALOG_H
