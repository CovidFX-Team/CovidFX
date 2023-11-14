#include "homescreen.h"
#include "ui_homescreen.h"

homescreen::homescreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::homescreen)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Albania");
    ui->comboBox->addItem("Algeria");
    ui->comboBox->addItem("Angola");
    ui->comboBox->addItem("Antigua and Barbuda");
    ui->comboBox->addItem("Argentina");
    ui->comboBox->addItem("Armenia");
    ui->comboBox->addItem("Australia");
    ui->comboBox->addItem("Austria");
    ui->comboBox->addItem("Azerbaijan");
    ui->comboBox->addItem("Bahamas");
    ui->comboBox->addItem("Bahrain");
    ui->comboBox->addItem("More countries to be read from database...");

    ui->comboBox_2->addItem("GDP Per Capita");
    ui->comboBox_2->addItem("Total Cases Per Million");
    ui->comboBox_2->addItem("Total Deaths Per Million");
    ui->comboBox_2->addItem("Total Deaths Per Case");
}

homescreen::~homescreen()
{
    delete ui;
}
