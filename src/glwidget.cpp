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
    helper->paint(&painter, event, getCurrTime()/1000, m_boudingBox);
    painter.end();
}

void GLWidget::mousePressEvent(QMouseEvent * event)
{
    if(buttonPressesd(Vec2i(event->x(),event->y())) == 1)
    {
        m_pausingTime.push_back(std::chrono::high_resolution_clock::now());
    }
    else if((buttonPressesd(Vec2i(event->x(),event->y())) == 2))
    {
        bool bo = m_pausingTime.size()%2;
        m_pausingTime.clear();
        auto now = std::chrono::high_resolution_clock::now();
        m_pausingTime.push_back(now);
        if(!bo)
            m_pausingTime.push_back(now);
    }
};

long GLWidget::getCurrTime()
{
    long ms = 0;
    for(unsigned i=0;i<m_pausingTime.size()/2;i++)
    {
        ms += std::chrono::duration_cast<std::chrono::milliseconds>(m_pausingTime[i+1] - m_pausingTime[i]).count();
    }

    if(m_pausingTime.size()%2)
    {
        ms += std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-m_pausingTime.back()).count();
    }
    return ms;
}

bool GLWidget::isInBB(Vec2i _point, Vec2T<Vec2i> _bb)
{
    Vec2i pos = _bb[1] - _point;
    Vec2i neg = _bb[0] - _point;

    return (pos > 0)&&(neg < 0);
}


int GLWidget::buttonPressesd(Vec2i _point) const
{
    for(unsigned i=0; i<m_boudingBox.size(); i++)
    {
        if(isInBB(_point,m_boudingBox[i]))
            return i;
    }
    return -1;
}

