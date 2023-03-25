#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QHostInfo>
#include<QWidget>
#include <QTcpSocket>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_tcpClient=new QTcpSocket(this);
    connect(m_tcpClient,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(m_tcpClient,SIGNAL(readyRead()),this,SLOT(onSocketReadyRead()));
}
//接收
void MainWindow::onSocketReadyRead()
{
    while(m_tcpClient->canReadLine())
        ui->editMessage->appendPlainText("[接收] "+m_tcpClient->readLine());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_tcpClient;
}

//点击连接
void MainWindow::on_btnConnectSever_clicked()
{
    QString ip="101.42.169.124";
    quint16 port=5000;
    m_tcpClient->connectToHost(QHostAddress(ip),port);
}

void MainWindow::onConnected()
{
    ui->labelSeverStatus->setText("status: 已连接");
}
//点击发送
void MainWindow::on_sendMessage_clicked()
{
    QString msg=ui->editSendMessage->toPlainText();
    ui->editMessage->appendPlainText("[输出] "+msg);
    ui->editSendMessage->clear();
    m_tcpClient->write(msg.toUtf8().data());
}

