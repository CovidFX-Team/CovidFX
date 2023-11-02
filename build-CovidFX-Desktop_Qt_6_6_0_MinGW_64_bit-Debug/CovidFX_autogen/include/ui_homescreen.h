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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_homescreen
{
public:
    QLabel *label;

    void setupUi(QDialog *homescreen)
    {
        if (homescreen->objectName().isEmpty())
            homescreen->setObjectName("homescreen");
        homescreen->resize(400, 300);
        homescreen->setAutoFillBackground(false);
        homescreen->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(homescreen);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 100, 301, 91));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(homescreen);

        QMetaObject::connectSlotsByName(homescreen);
    } // setupUi

    void retranslateUi(QDialog *homescreen)
    {
        homescreen->setWindowTitle(QCoreApplication::translate("homescreen", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("homescreen", "This is the home screen of the CovidFX application.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class homescreen: public Ui_homescreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMESCREEN_H
