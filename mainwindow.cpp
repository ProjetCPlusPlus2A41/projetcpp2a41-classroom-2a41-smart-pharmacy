#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_login_clicked()
{
    QString username = ui->usernameline->text();
    QString password = ui->paswordline->text();

    if (password == "1234" && username == "pharm") {
        QMessageBox::information(this, "Success", "You are logged in successfully");

        GestionProduit *gp = new GestionProduit();
        gp->setAttribute(Qt::WA_DeleteOnClose); // Ensures memory is freed when closed
        this->hide();
        gp->show(); // Shows the window without blocking the main thread
    }
    else {
        QMessageBox::warning(this, "Failed", "Check your username and password");
    }
}

