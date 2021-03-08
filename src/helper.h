#ifndef HELPER_H
#define HELPER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>
#include <QSoundEffect>
#include "VecXT.h"


class Helper
{
public:
    Helper(double frequency,double);

public:
    void paint(QPainter *painter, QPaintEvent *event, long long elapsed, std::vector<Vec2T<Vec2i>> &boudingBox);
    void drawButton(QPainter *painter, int width, int height, int xRadius, int yRadius, std::string name, int xNameOffset, int yNameOffset, double scalingFactor);

private:

    QColor m_backGroundColor;
    QColor m_frontColor;
    QFont m_textFont;
    QPen m_buttonPen;
    QPen m_textPen;
    QSoundEffect tic;
    long m_period;
    bool m_state;
    long m_elapsed;
    long long m_length;

};

#endif
