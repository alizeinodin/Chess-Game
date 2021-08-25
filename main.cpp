#include <iostream>
#include "include/king.h"
#include "include/util.h"
#include "include/pawn.h"
#include "include/rook.h"
#include "include/bishop.h"
#include "include/knight.h"
#include <array>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include "include/connection.h"
#include <QDebug>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/media/knight2.png"));

    QQuickStyle::setStyle("Material");
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
