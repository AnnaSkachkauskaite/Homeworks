#include "cannon.h"
#include <QTransform>
#include <QColor>
#include <QBrush>
#include <QWidget>

Cannon::Cannon(int newRadius, int newWidth, int newHeight)
{
    radius = newRadius;
    angle = 45;
    width = radius / 10;
    height = radius / 2;
    widthRect = newWidth * 2;
    heightRect = newHeight * 2;
}

void Cannon::up()
{
    if (angle >= 89)
        return;
    angle = angle + 2;
}

void Cannon::down()
{
    if (angle <= 2)
        return;
    angle = angle - 2;
}

int Cannon::getHeigh()
{
    return height;
}

int Cannon::getWidth()
{
    return width;
}

int Cannon::getRadius()
{
    return radius;
}

int Cannon::getangle()
{
    return angle;
}


QRectF Cannon::boundingRect() const
{
    return QRectF(0, 0, widthRect, heightRect);
}
void Cannon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QTransform *transformation = new QTransform();
    transformation->translate(0, widget->height() - 1);
    transformation->rotate(-90);
    painter->setTransform(*transformation);
    painter->setPen(Qt::green);
    transformation->translate(-radius * 2, -radius);
    painter->setTransform(*transformation);
    painter->drawPie(radius, 0.0, 2 * radius, 2 * radius, -90 * 16 ,90 * 16);
    transformation->translate(radius * 2, radius);
    painter->setTransform(*transformation);

    painter->setPen(Qt::black);
    transformation->rotate(-angle);
    transformation->translate(0, radius);
    transformation->translate(-width / 2 , 0);
    painter->setTransform(*transformation);
    painter->drawRect(0, 0, width, height);
    transformation->translate(width / 2, height);
    transformation->rotate(angle);
    painter->setTransform(*transformation);
}

