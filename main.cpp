#include <QApplication>
#include <QQmlApplicationEngine>

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QDebug>
#include <QQmlContext>
#include <QSettings>

#include "rcontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QCoreApplication::setOrganizationName("RA");
    QCoreApplication::setApplicationName("Yancı");
    QCoreApplication::setApplicationVersion("0.1");

    QCommandLineParser parser;
    parser.setApplicationDescription("Test helper");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("source", QCoreApplication::translate("main", "Source file to copy."));
    parser.addPositionalArgument("destination", QCoreApplication::translate("main", "Destination directory."));

    QCommandLineOption tHostOption(QStringList() << "server" << "host");
    QCommandLineOption tClientOption(QStringList() << "client");

    parser.addOption(tHostOption);
    parser.addOption(tClientOption);

    parser.process(app);

//    if(parser.isSet(tHostOption))
//    {
//        qDebug() << "this is host app";

//        RGameObject* tServer = new RGameObject();
//        tServer->init("", false);
//    }
//    else if(parser.isSet(tClientOption))
//    {
//        qDebug() << "this is client app";

//        RGameClient* tClient = new RGameClient();
//        tClient->init();
//    }

    RController* controller = new RController();

    QSettings tSettings;

    int tValue = 0;

    tValue = tSettings.value("normalDone").toInt();
    if(tValue != 0)
        controller->setNormalDone(tValue);
    else
        controller->setNormalDone(-100);

    tValue = tSettings.value("okeyDone").toInt();
    if(tValue != 0)
        controller->setOkeyDone(tValue);
    else
        controller->setOkeyDone(-200);

    tValue = tSettings.value("doubleOkeyDone").toInt();
    if(tValue != 0)
        controller->setDoubleOkeyDone(tValue);
    else
        controller->setDoubleOkeyDone(-300);

    tValue = tSettings.value("directDone").toInt();
    if(tValue != 0)
        controller->setDirectDone(tValue);
    else
        controller->setDirectDone(-200);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("controller", controller);
//    engine.rootContext()->setContextProperty("gameObj", controller->game());

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
