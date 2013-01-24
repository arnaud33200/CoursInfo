#include "HelloBeanService.hpp"

#include <qjson/parser.h>
#include <qjson/qobjecthelper.h>
#include <QtNetwork>

HelloBeanService::HelloBeanService(const QString &serverurl)
    : m_serverurl (serverurl)
{
}

HelloBean *HelloBeanService::get(const QString &name)
{
    QNetworkRequest requete (QUrl("http://"+m_serverurl+"/HelloBeanREST/rest/hello/"+name));

    requete.setHeader (QNetworkRequest::ContentTypeHeader,"application/json");
    requete.setRawHeader("Accept","application/json");

    QNetworkAccessManager* m = new QNetworkAccessManager;

    QEventLoop *loop = new QEventLoop;
    connect (m, SIGNAL (finished(QNetworkReply*)), loop, SLOT (quit()));

    QNetworkReply* r = m->get (requete);

    loop->exec();

    QByteArray array = r->readAll();
    qDebug() << array;
    QJson::Parser p;
    QVariant v = p.parse(array);

    HelloBean * bean = new HelloBean;
    QJson::QObjectHelper::qvariant2qobject(v.toMap()["hellobean"].toMap(), bean);

    return bean;
}
