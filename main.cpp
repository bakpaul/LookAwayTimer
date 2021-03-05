
#include "src/window.h"

#include <QApplication>
#include <QSurfaceFormat>
#include <thread>
#include "src/Sound.h"

int main(int argc, char *argv[])
{
    char** temp;
    int a;
    QApplication app(a,temp);

    QSurfaceFormat fmt;
    fmt.setSamples(4);
    QSurfaceFormat::setDefaultFormat(fmt);
//
//    if(argc > 1)
//    {
//        Sound sound(argv[1]);
//        sound.play();
//        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
//        sound.stop();
//    }


    Window window(1,1600);
    window.show();
    return app.exec();
}
