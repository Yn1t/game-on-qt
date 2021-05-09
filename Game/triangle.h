#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPolygon>
#include <QTimer>
#include <QDebug>
#include <QCursor>


#include <object.h>

class Triangle : public Object
{

public:
    explicit Triangle(QObject* parent = 0);
    ~Triangle();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // TRIANGLE_H
