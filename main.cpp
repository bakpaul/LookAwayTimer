
#include "src/window.h"

#include <QApplication>
#include <QSurfaceFormat>

int main(int argc, char *argv[])
{
    char** temp;
    int a;
    QApplication app(a,temp);

    QSurfaceFormat fmt;
    fmt.setSamples(4);
    QSurfaceFormat::setDefaultFormat(fmt);

    Window window(1,1600);
    window.show();
    return app.exec();
}
