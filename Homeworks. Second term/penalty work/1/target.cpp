#include "target.h"
#include <QPainter>
#include <stdlib.h>
#include <QDateTime>

Target::Target(int radiusTarget, int widthRectTarget, int heightRectTarget)
{
    radius = radiusTarget;
    widthRect = widthRectTarget;
    heightRect = heightRectTarget;
    qsrand(QDateTime::currentMSecsSinceEpoch());
    position = QPoint(radius * 4 + qrand() % 400, radius * 2 + qrand() % 200);
}

QRectF Target::boundingRect() const
{
    return QRectF(0, 0, widthRect, heightRect);
}

QRect Target::getPosition() const
{
    return QRect(position - QPoint(radius, radius), position + QPoint(radius, radius));
}

void Target::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::red);
    painter->drawEllipse(position, radius, radius);
}

void Target::replaceTarget(int radiusTarget)
{
    if (radiusTarget > 8)
        radius = radiusTarget;
    position = QPoint(radius * 4 + qrand() % 400, radius * 2 + qrand() % 200);
}

int Target::radiusTarget()
{
    return radius;
}
