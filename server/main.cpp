/**
 * @file main.cpp
 * @author Bagrova Polina
 */

#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    return a.exec();
}
