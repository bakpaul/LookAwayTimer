#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <chrono>
#include <ctime>
#include <iostream>
#include <QMouseEvent>
#include "VecXT.h"

class Helper;

class GLWidget : public QOpenGLWidget
{
    //Q_OBJECT

public:
    GLWidget(Helper *helper, QWidget *parent);

    virtual void mousePressEvent(QMouseEvent * event);

    static bool isInBB(Vec2i, Vec2T<Vec2i>);

public slots:
    void animate();


protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int buttonPressesd(Vec2i) const;

    Helper *helper;

    std::chrono::time_point<std::chrono::high_resolution_clock> m_begin;
    std::vector<std::chrono::time_point<std::chrono::high_resolution_clock> > m_pausingTime;
    long getCurrTime();

    long long m_elapsed;

    std::vector<Vec2T<Vec2i>> m_boudingBox;



};

#endif
