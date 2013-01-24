#ifndef HELLOBEANSERVICE_HPP
#define HELLOBEANSERVICE_HPP

#include <QVariant>
#include <QObject>
#include "HelloBean.hpp"

class HelloBeanService : public QObject
{
    Q_OBJECT
public:
    HelloBeanService(const QString &serverurl);
    HelloBean* get(const QString &name);

private :
    QString m_serverurl;
};

#endif // HELLOBEANSERVICE_HPP
