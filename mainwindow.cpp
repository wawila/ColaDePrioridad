#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Practica_Monticulos window;
    window.setModal(true);
    window.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Narios window;
    window.setModal(true);
    window.exec();
}
