#ifndef QAUTHTEST_H
#define QAUTHTEST_H

#include <QObject>
#include <QOAuth2AuthorizationCodeFlow>
#include <QDesktopServices>
#include <QOAuthHttpServerReplyHandler>

class QOAuth2Test : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString textToDisplay READ getToDisplay WRITE setToDisplay NOTIFY textToDisplayChanged)
public:
    explicit QOAuth2Test(QObject *parent = nullptr);
    Q_INVOKABLE void grant();
    QString getToDisplay() const;
    void setToDisplay(const QString &value);

signals:
    void textToDisplayChanged();

public slots:
    void onGranted();
private:
    QOAuth2AuthorizationCodeFlow google;
    QString toDisplay;
};

#endif // QAUTHTEST_H
