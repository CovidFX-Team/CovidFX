/********************************************************************************
** Form generated from reading UI file 'homescreen.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMESCREEN_H
#define UI_HOMESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_homescreen
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QComboBox *comboBox;
    QGroupBox *groupBox_2;
    QComboBox *comboBox_2;
    QLabel *label;

    void setupUi(QDialog *homescreen)
    {
        if (homescreen->objectName().isEmpty())
            homescreen->setObjectName("homescreen");
        homescreen->resize(826, 517);
        QPalette palette;
        QBrush brush(QColor(85, 170, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(61, 121, 182, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        QBrush brush2(QColor(43, 86, 129, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        homescreen->setPalette(palette);
        homescreen->setAutoFillBackground(false);
        homescreen->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget = new QWidget(homescreen);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(40, 170, 161, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        groupBox = new QGroupBox(homescreen);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 60, 161, 111));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(1, 30, 161, 24));
        groupBox_2 = new QGroupBox(homescreen);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(40, 10, 161, 51));
        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(0, 20, 161, 24));
        label = new QLabel(homescreen);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 20, 531, 271));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        label->setPalette(palette1);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(homescreen);

        QMetaObject::connectSlotsByName(homescreen);
    } // setupUi

    void retranslateUi(QDialog *homescreen)
    {
        homescreen->setWindowTitle(QCoreApplication::translate("homescreen", "CovidFX", nullptr));
        pushButton->setText(QCoreApplication::translate("homescreen", "Add another country...", nullptr));
        pushButton_2->setText(QCoreApplication::translate("homescreen", "Generate Graph", nullptr));
        groupBox->setTitle(QCoreApplication::translate("homescreen", "Country #1", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("homescreen", "Statistic", nullptr));
        label->setText(QCoreApplication::translate("homescreen", "This is where the data will be displayed.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class homescreen: public Ui_homescreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMESCREEN_H
