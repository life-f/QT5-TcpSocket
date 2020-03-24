/**
 * @file mainwindow.cpp
 * @brief client
 * @author Bagrova Polina
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socketClient = new QTcpSocket(this);
    socketClient->connectToHost("localhost", 1337, QTcpSocket::ReadWrite);
    if(socketClient->waitForConnected(30000)) {
        qInfo() << "Connected!";
        qInfo() << socketClient->peerAddress();
    } else{
         QMessageBox::information(NULL,QObject::tr("Информация"),tr("Нет подключения к серверу."));
    }

    connect(socketClient, &QTcpSocket::readyRead,
            this, &MainWindow::readSocket);
    connect(ui->send, &QPushButton::clicked,
            this, &MainWindow::execButtonAction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::execButtonAction()
{
    socketClient->write(ui->nick->text().toUtf8()
                        + " " + ui->message->text().toUtf8());
}

void MainWindow::readSocket()
{
    QString data = QString(socketClient->readAll());
    ui->textEdit->append(data);
}
