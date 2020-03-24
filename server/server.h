/**
 * @file server.h
 * @brief server
 * @author Bagrova Polina
 */
#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QtNetwork>

class Server : public QObject
{
    Q_OBJECT
private:
    /**
     * @brief connecting to the tcpServer
     */
    QTcpServer* tcpServer;
    /**
     * @brief connecting to the client
     */
    QTcpSocket* client;
    /**
     * @brief list of clients
     */
    QList <QTcpSocket*> clients;
    QFile f;
    QStringList list;
    int k = 0;

public:
    /**
     * @brief Server Constructor
     * @param parent
     */
    explicit Server(QObject *parent = nullptr);

private slots:
    /**
     * @brief connect User
     */
    void connectUser();
    /**
     * @brief message from client
     */
    void runClientAction();
    /**
     * @brief disconnect User
     */
    void disconnectUser();
    /**
     * @brief send 10 messages for new user
     */
    void send10Message();

signals:
    /**
     * @brief server close
     */
    void serverClose();

};

#endif // SERVER_H
