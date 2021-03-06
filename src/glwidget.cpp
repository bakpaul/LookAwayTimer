#include "glwidget.h"
#include "helper.h"

#include <QPainter>
#include <QTimer>

GLWidget::GLWidget(Helper *helper, QWidget *parent)
    : QOpenGLWidget(parent), helper(helper)
{
    m_begin = std::chrono::high_resolution_clock::now();
    setMinimumSize(520,130);
    setMaximumSize(1640,400);
    setAutoFillBackground(false);
}

void GLWidget::animate()
{
    m_elapsed = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now()-m_begin).count();
    update();
}

void GLWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    helper->paint(&painter, event, m_elapsed, m_boudingBox);
    painter.end();
}
