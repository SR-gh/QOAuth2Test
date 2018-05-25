// Adapted from http://blog.qt.io/blog/2017/01/25/connecting-qt-application-google-services-using-oauth-2-0/
// Change : authorize http://localhost:8080/ without trailing « cb ».

#include "qoauth2test.h"
#include <QNetworkReply>

QOAuth2Test::QOAuth2Test(QObject *parent) : QObject(parent)
{
    // Launch browser for authorization request
    connect(&google, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser,
        &QDesktopServices::openUrl);
    // Receive answer from authorization request process
    connect(&google, &QOAuth2AuthorizationCodeFlow::granted, this, &QOAuth2Test::onGranted);
    google.setScope("email");
    QString authUri = "https://accounts.google.com/o/oauth2/auth";
    QString clientId = "copy your whatever.apps.googleusercontent.com URL here";
    QString tokenUri = "https://accounts.google.com/o/oauth2/token";
    QString clientSecret = "copy your secret here";
    quint16 port = 8080;
    google.setAuthorizationUrl(authUri);
    google.setClientIdentifier(clientId);
    google.setAccessTokenUrl(tokenUri);
    google.setClientIdentifierSharedKey(clientSecret);
    qInfo() << "QOAuth2Test : creating reply handler server. This may take some time…";
    auto replyHandler = new QOAuthHttpServerReplyHandler(port, this);
    qInfo() << "QOAuth2Test reply handler server created";
    google.setReplyHandler(replyHandler);
    qInfo() << "QOAuth2Test reply handler set";
}

void QOAuth2Test::grant()
{
    google.grant();
}

void QOAuth2Test::onGranted()
{
    qInfo() << google.token();
    setToDisplay(google.token());
}

QString QOAuth2Test::getToDisplay() const
{
    return toDisplay;
}

void QOAuth2Test::setToDisplay(const QString &value)
{
    if (toDisplay != value)
    {
        toDisplay = value;
        emit textToDisplayChanged();
    }
}
