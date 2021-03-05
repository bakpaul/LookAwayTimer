#include "glwidget.h"
#include "window.h"

#include <QGridLayout>
#include <QLabel>
#include <QTimer>

Window::Window(double freq,double length) : helper(freq,length)
{
    setWindowTitle(tr("Look away timer"));

    GLWidget *openGL = new GLWidget(&helper, this);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(openGL, 0, 0);
    setLayout(layout);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, openGL, &GLWidget::animate);
    timer->start(10);

}
