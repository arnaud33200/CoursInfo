#include <QtCore/QCoreApplication>


#include <QDebug>
#include <QTimer>
#include "HelloBeanService.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    HelloBeanService s  ("localhost:8080");

    HelloBean * bean = s.get("Vincent");
    qDebug() << bean->getHelloMsg() + bean->getClientName();

    delete bean;

    return a.exec();
}
