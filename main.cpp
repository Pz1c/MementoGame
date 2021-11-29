#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "cpp/qmementocore.h"
#include "cpp/tgaimageprovider.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<QMementoCore>("ua.sp.memento", 0, 1, "MementoCore");

    QQmlApplicationEngine engine;
    //QQmlImageProviderBase *imgprovider = new TgaImageProvider();
    //engine.addImageProvider(QLatin1String("tga"), new TgaImageProvider());


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    //QDeclarativeContext::setContextProperty("imagePath",imagePath);
    //engine.rootContext()->setContextProperty("applicationPath", "file://"+qApp->applicationDirPath()+ "/");

    return app.exec();
}
