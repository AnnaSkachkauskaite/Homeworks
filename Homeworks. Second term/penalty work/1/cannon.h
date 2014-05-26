#pragma once
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>

///Class for cannon
class Cannon : public QGraphicsItem
{
public:
    Cannon(int newRadius, int newWidth, int newHeight);

    QRectF boundingRect() const;
    ///Draw cannon on the hill
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


    ///Increases angle cannon
    void up();
    ///Decreases angle cannon
    void down();

    int getHeigh();
    int getWidth();
    int getRadius();
    int getangle();

private:
    int radius;
    int angle;
    int width;
    int height;
    int widthRect;
    int heightRect;
};
