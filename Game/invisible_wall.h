#ifndef INVISIBLE_WALL_H
#define INVISIBLE_WALL_H

#include "static_object.h"

class Invisible_wall : public Static_object
{
    Q_OBJECT
public:
    explicit Invisible_wall(QObject* parent);
    ~Invisible_wall();
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // INVISIBLE_WALL_H
