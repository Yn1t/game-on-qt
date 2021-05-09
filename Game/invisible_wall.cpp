#include "invisible_wall.h"

Invisible_wall::Invisible_wall(QObject* parent) : Static_object(parent)
{
    Q_UNUSED(parent);
}


Invisible_wall::~Invisible_wall()
{

}

void Invisible_wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->drawRect(0,0,40,30);
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Invisible_wall::boundingRect() const
{
    return QRectF(0,0,40,30);
}
