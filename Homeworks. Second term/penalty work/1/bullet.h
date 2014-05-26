#pragma once
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QElapsedTimer>
#include <QTransform>

///Class for bullet (speed is variable)
class Bullet : public QGraphicsItem
{
public:
    Bullet(double rad, double newSpeed, double beginangle,
               double beginTranslate, double widthRectBall, double heightRectBall);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setPosition(double time);
    ///Change angle(when cannon's angle changed)
    void setAngle(int newangle);

    void startTimer();
    void stopTimer();


    void speedUp();
    void speedDown();

    QPoint getPosition();

    ///Return speed in current moment
    int getSpeed();

    int getRadius();
    void setRadius(int radius);

private:
    void translate(int height);
    ///Rotate speed vector when angle changes
    void translateSpeed(int newangle);

    QPoint speed;
    QPoint start;
    double angle;
    double radiusBall;
    double time;
    ///Acceleration of free fall
    QPoint g;
    double widthRect;
    double heightRect;
    QElapsedTimer timer;
    QPoint currPosition;
    QTransform transformation;
    double beginTranslation;
};
