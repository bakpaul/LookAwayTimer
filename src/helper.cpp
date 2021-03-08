#include "helper.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <iostream>
#include <math.h>

#define BORDERS 0.05
#define RATIO 4.1

Helper::Helper(double frequency,double completeTime)
{
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::black);
    gradient.setColorAt(1.0, Qt::black);


    m_buttonPen = QPen(Qt::black);
    m_buttonPen.setWidth(1);
    m_textPen = QPen(Qt::black);
    m_textPen.setWidth(7);

    m_textFont.setPixelSize(150);
    m_backGroundColor= QColor(160,205,220);
    m_frontColor= QColor(50,50,50);
}

void Helper::drawButton(QPainter *painter, int width, int height, int xRadius, int yRadius, std::string name, int xNameOffset, int yNameOffset, double scalingFactor)
{

    painter->setBrush(QBrush(m_frontColor));
    painter->setPen(m_buttonPen);

    painter->drawRoundedRect(QRectF(0,0, width,height),
                             xRadius,
                             yRadius);

    painter->translate(xNameOffset, yNameOffset);

    painter->setPen(m_textPen);
    painter->setPen(QPen(m_backGroundColor));
    m_textFont.setPixelSize(height);
    painter->setFont(m_textFont);
    QString s_temp(name.c_str());
    painter->drawText(QRectF(0,0, width,height), Qt::AlignCenter, s_temp);

    painter->translate(-xNameOffset, -yNameOffset);

}

void Helper::paint(QPainter *painter, QPaintEvent *event, long long _elapsed, std::vector<Vec2T<Vec2i>> &boudingBox)
{
    double height;
    double fact = (( (double) event->rect().width() ) / ((double) event->rect().height())) / RATIO;
    height = event->rect().height() * ( (fact> 1) ? 1 : fact) ;

    double centerx, centery;
    centerx = event->rect().width() *((fact>1) ? (fact - 1) / 2.0 / RATIO : 0);
    centery = event->rect().height() *((fact>1) ? 0 : (1-fact) / 2.0);

    boudingBox.resize(3,Vec2T<Vec2i>(Vec2i(0)));

    painter->fillRect(event->rect(), QBrush(m_backGroundColor));


    Vec2i painterPose(0,0);

    //First offset
    painter->translate(centerx,centery);
    painterPose = Vec2i(centerx,centery);

    //First button
    painter->translate(height*BORDERS , height*BORDERS );

    drawButton(painter, height*(1-2*BORDERS),height*(1-2*BORDERS), height/5.0, height/5.0,std::string("L"),0,0,height);

    painterPose += Vec2i(height*BORDERS , height*BORDERS);
    boudingBox[0][0] = painterPose;
    boudingBox[0][1] = Vec2i(painterPose[0] + height*(1-2*BORDERS) ,painterPose[1] + height*(1-2*BORDERS));

    //Button 2

    painter->translate(height*1, 0);
    painter->save();

    drawButton(painter, height*(0.5-1.5*BORDERS),height*(0.5-1.5*BORDERS), height/10.0, height/10.0,std::string("⏸"),0,height*BORDERS*0.8,height);

    painterPose += Vec2i(height*1, 0);
    boudingBox[1][0] = painterPose;
    boudingBox[1][1] = Vec2i(painterPose[0] + height*(0.5-1.5*BORDERS),painterPose[1] + height*(0.5-1.5*BORDERS));


    //Button 3
    painter->translate(0, height*((1 - 2*BORDERS)*0.5+0.5*BORDERS))    ;

    drawButton(painter, height*(0.5-1.5*BORDERS),height*(0.5-1.5*BORDERS), height*(0.5-1.5*BORDERS)/5.0, height*(0.5-1.5*BORDERS)/5.0,std::string("↺"),0, height*BORDERS*0.3,height);

    painterPose += Vec2i(0, height*((1 - 2*BORDERS)*0.5+0.5*BORDERS));
    boudingBox[2][0] = painterPose;
    boudingBox[2][1] = Vec2i(painterPose[0] +height*(0.5-1.5*BORDERS),painterPose[1] + height*(0.5-1.5*BORDERS));




    //Timer
    painter->restore();
    painter->translate(height*0.5, 0);
    painter->setPen(m_textPen);
    painter->setPen(QPen(m_frontColor));
    m_textFont.setPixelSize(height);
    painter->setFont(m_textFont);
    char s_timeT[500];
    sprintf(s_timeT,"%02lld:%02lld",_elapsed/60,_elapsed%60) ;
    QString s_tempT(s_timeT);
    painter->drawText(QRectF(0,0, height*(1-2*BORDERS)*2.8,height*(1-2*BORDERS)), Qt::AlignCenter, s_tempT);

}
