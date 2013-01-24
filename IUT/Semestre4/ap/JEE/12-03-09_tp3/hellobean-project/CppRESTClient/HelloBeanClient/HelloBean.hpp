#ifndef HELLOBEAN_HPP
#define HELLOBEAN_HPP

#include <QObject>

class HelloBean : public QObject
{
    Q_OBJECT

public:
    HelloBean();

    QString getHelloMsg() const
    {
        return m_helloMsg;
    }

    QString getClientName() const
    {
        return m_clientname;
    }

public slots:
    void setHelloMsg(QString arg)
    {
        m_helloMsg = arg;
    }

    void setClientName(QString arg)
    {
        m_clientname = arg;
    }

private :
    Q_PROPERTY (QString helloMsg READ getHelloMsg WRITE setHelloMsg)
    QString m_helloMsg;

    Q_PROPERTY (QString clientName READ getClientName WRITE setClientName)
    QString m_clientname;
};

#endif // HELLOBEAN_HPP
