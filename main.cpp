#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "qoauth2test.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QOAuth2Test authTest;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("auth", &authTest);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
