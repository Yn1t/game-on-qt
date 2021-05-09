#include "triangle.h"

#include <math.h>
#pragma comment(lib, "User32.lib")

Triangle::Triangle(QObject* parent) : Object(parent)
{
    Q_UNUSED(parent);
}

Triangle::~Triangle()
{

}

QRectF Triangle::boundingRect() const
{
    return QRectF(-25,-40,50,80);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;
    polygon << QPoint(0,-40) << QPoint(25,40) << QPoint(-25,40);
    painter->setBrush(Qt::black);
    painter->drawPolygon(polygon);

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
