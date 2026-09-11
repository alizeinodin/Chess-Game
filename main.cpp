#include <array>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QIcon>
#include <QDebug>
#include "include/connection.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    app.setApplicationName(QStringLiteral("Bu-Ali Chess"));
    app.setOrganizationName(QStringLiteral("Bu-Ali Sina University"));
    app.setWindowIcon(QIcon(QStringLiteral(":/media/knight2.png")));

    QQuickStyle::setStyle(QStringLiteral("Material"));
    qmlRegisterType<connection>("connect", 1, 0, "Connect");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
