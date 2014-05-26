#include "bullet.h"
#include <QWidget>
#include <QTimer>
#include <QTransform>
#include <QRect>
#include  <QtCore/qmath.h>

Bullet::Bullet(double rad, double newSpeed, double beginangle,
                       double beginTranslate, double widthRectBall, double heightRectBall)
{
    radiusBall = rad;
    speed = QPoint(newSpeed, 0);
    currPosition = QPoint(0,0);
    time = 0;
    g = QPoint(0,10);
    widthRect = widthRectBall * 2;
    heightRect = heightRectBall * 2;
    beginTranslation = beginTranslate;
    start = QPoint(0, 0);
    timer.invalidate();
    currPosition = QPoint(0, 0);

    angle = 0;
    translateSpeed(beginangle);
    angle = beginangle;
}

QRectF Bullet::boundingRect() const
{
    return QRectF(0, 0, widthRect, heightRect);
}

void Bullet::setPosition(double time)
{
    startTimer();
    if (time == 0)
        time = timer.elapsed() / 300.0;
    currPosition.setX(speed.x() * time + start.x());
    currPosition.setY(speed.y() * time + g.y() * time * time / 2.0 + start.y());
}

void Bullet::startTimer()
{
    if (!timer.isValid())
        timer.start();
}

void Bullet::stopTimer()
{
    timer.invalidate();
}

void Bullet::setAngle(int newangle)
{
    translateSpeed(newangle);
    angle = newangle;
}

void Bullet::speedUp()
{
    translateSpeed(0);
    speed = QPoint(speed.x() + 3, speed.y());
    translateSpeed(2 * angle);
}

void Bullet::speedDown()
{
    translateSpeed(0);
    speed = QPoint(speed.x() - 3, speed.y());
    translateSpeed(2 * angle);
}

QPoint Bullet::getPosition()
{
    return currPosition;
}

int Bullet::getSpeed()
{
    int result = 0;
    if (speed.x() <= 0 || speed.y() >= 0)
        return 0;
    result = qSqrt(speed.x() * speed.x() + speed.y() * speed.y());
    return result;
}

int Bullet::getRadius()
{
    return radiusBall;
}

void Bullet::setRadius(int radius)
{
    radiusBall = radius;
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (!timer.isValid())
        return;
    translate(widget->height());
    painter->drawEllipse(QPoint(currPosition.x(), currPosition.y()) , radiusBall, radiusBall);
}

void Bullet::translate(int height)
{
    transformation.reset();
    transformation.translate(0, height - 1);
    transformation.rotate(-angle);
    transformation.translate(beginTranslation, 0);
    transformation.rotate(-angle);
    start = transformation.map(QPoint(0,0));
}


void Bullet::translateSpeed(int newangle)
{
    QTransform transformSpeed;
    transformSpeed.rotate(angle - newangle);
    speed = transformSpeed.map(speed);
}
