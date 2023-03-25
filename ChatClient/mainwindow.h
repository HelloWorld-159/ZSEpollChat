#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QTcpSocket;
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QTcpSocket *m_tcpClient; // socket

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnConnectSever_clicked();

    void on_sendMessage_clicked();

    void onSocketReadyRead();

    void onConnected();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
