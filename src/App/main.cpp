#include "App/MainWindow.h"
#include "Renderer/SpriteCache.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    app.setApplicationName("AdventureQuest");
    app.setOrganizationName("AdventureQuest");
    app.setApplicationVersion("2.0.0");

#if defined(Q_OS_IOS)
    // iOS-specific: ensure proper high-DPI rendering
    app.setAttribute(Qt::AA_UseHighDpiPixmaps);
#endif

    AQ::MainWindow window;

#if defined(Q_OS_IOS) || defined(Q_OS_ANDROID)
    window.showFullScreen();
#else
    window.show();
#endif

    return app.exec();
}
