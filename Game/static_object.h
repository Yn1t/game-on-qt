#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>

class Static_object : public QGraphicsItem, public QObject
{
public:
    explicit Static_object(QObject* parent = 0);
    ~Static_object();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    virtual QRectF boundingRect() const = 0;

};

#endif // STATIC_OBJECT_H
