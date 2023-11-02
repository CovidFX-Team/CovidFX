#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if (username == "admin" && password == "admin") {
        QMessageBox::information(this, "Log in", "Username and password are correct - logging in.");
        hide();
        home = new homescreen(this);
        home->show();
    } else {
        QMessageBox::warning(this, "Log in", "Username and password are incorrect.");
    }
}

