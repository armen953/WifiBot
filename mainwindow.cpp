#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtNetwork>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->haut->setArrowType(Qt::UpArrow);
    this->ui->bas->setArrowType(Qt::DownArrow);
    this->ui->droite->setArrowType(Qt::RightArrow);
    this->ui->gauche->setArrowType(Qt::LeftArrow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnConnect_clicked()
{

}

void MainWindow::on_btnDeconnect_clicked()
{

}
