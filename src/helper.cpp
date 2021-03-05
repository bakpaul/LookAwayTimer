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
    m_linePen = QPen(Qt::black);
    m_linePen.setWidth(7);
    textPen = QPen(Qt::black);
    textFont.setPixelSize(150);


}

void Helper::paint(QPainter *painter, QPaintEvent *event, long long _elapsed)
{
    double height;
    double fact = (( (double) event->rect().width() ) / ((double) event->rect().height())) / RATIO;
    height = event->rect().height() * ( (fact> 1) ? 1 : fact) ;

    double centerx, centery;
    centerx = event->rect().width() *((fact>1) ? (fact - 1) / 2.0 / RATIO : 0);
    centery = event->rect().height() *((fact>1) ? 0 : (1-fact) / 2.0);

    auto backgroudColor= QColor(160,205,220);
    auto frontColor= QColor(50,50,50);


    backgroundBrush = QBrush(backgroudColor);
    frontBrush = QBrush(frontColor);

    painter->fillRect(event->rect(), backgroundBrush);
//        painter->translate(900, 500);

    painter->setBrush(frontBrush);
    painter->setPen(m_buttonPen);

    painter->translate(centerx,centery);


    painter->translate(height*BORDERS , height*BORDERS );
    painter->drawRoundedRect(QRectF(0,0, height*(1-2*BORDERS),height*(1-2*BORDERS)),
                             height/5.0,
                             height/5.0);
    painter->setPen(m_linePen);
    painter->setPen(QPen(backgroudColor));
    textFont.setPixelSize(height);
    painter->setFont(textFont);
    char s_time[10];
    sprintf(s_time,"R\0") ;
    QString s_temp(s_time);
    painter->drawText(QRectF(0,0, height*(1-2*BORDERS),height*(1-2.5*BORDERS)), Qt::AlignCenter, s_temp);


    painter->setBrush(frontBrush);
    painter->setPen(m_buttonPen);
    painter->translate(height*1, 0);
    painter->save();
    painter->drawRoundedRect(QRectF(0,0, height*(0.5-1.5*BORDERS),height*(0.5-1.5*BORDERS)),
                             height/10.0,
                             height/10.0);
    painter->translate(0, height*BORDERS*0.8);
    painter->setPen(m_linePen);
    painter->setPen(QPen(backgroudColor));
    textFont.setPixelSize(height*(0.5-1.5*BORDERS));
    painter->setFont(textFont);
    char s_time2[10];
    sprintf(s_time2,"⏸\0") ;
    QString s_temp2(s_time2);
    painter->drawText(QRectF(0,0, height*(0.5-1.5*BORDERS),height*(0.5-1.5*BORDERS)), Qt::AlignCenter, s_temp2);

    painter->translate(0, -height*BORDERS*0.8);



    painter->setBrush(frontBrush);
    painter->setPen(m_buttonPen);
    painter->translate(0, height*((1 - 2*BORDERS)*0.5+0.5*BORDERS))    ;
    painter->drawRoundedRect(QRectF(0,0, height*(0.5-1.5*BORDERS),height*(0.5-1.5*BORDERS)),
                             height*(0.5-1.5*BORDERS)/5.0,
                             height*(0.5-1.5*BORDERS)/5.0);
    painter->translate(0, height*BORDERS*0.3);
    painter->setPen(m_linePen);
    painter->setPen(QPen(backgroudColor));
    textFont.setPixelSize(height*(0.5-1.5*BORDERS));
    painter->setFont(textFont);
    char s_time3[10];
    sprintf(s_time3,"↺\0") ;
    QString s_temp3(s_time3);
    painter->drawText(QRectF(0,0, height*(0.5-1.5*BORDERS),height*(0.5-1.5*BORDERS)), Qt::AlignCenter, s_temp3);
    painter->translate(0, -height*BORDERS*0.3);



    painter->restore();
    painter->translate(height*0.5, 0);

    painter->setPen(m_linePen);
    painter->setPen(QPen(frontColor));
    textFont.setPixelSize(height);
    painter->setFont(textFont);
    char s_timeT[500];
    sprintf(s_timeT,"%02lld:%02lld",_elapsed/60,_elapsed%60) ;
    QString s_tempT(s_timeT);
    painter->drawText(QRectF(0,0, height*(1-2*BORDERS)*2.8,height*(1-2*BORDERS)), Qt::AlignCenter, s_tempT);

}
