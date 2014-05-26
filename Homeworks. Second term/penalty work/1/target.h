#pragma once
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QPoint>

class Target : public QGraphicsItem
{
public:
    Target(int radiusTarget, int widthRectTarget, int heightRectTarget);

    QRectF boundingRect() const;
    ///Return rectangle with target
    QRect getPosition() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    ///Cange target radius and put it in a random place on the screen
    void replaceTarget(int radiusTarget);

    /// Return radius
    int radiusTarget();

private:
    int radius;
    QPoint position;
    int widthRect;
    int heightRect;
};
