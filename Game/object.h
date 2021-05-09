#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QPolygon>
#include <QTimer>
#include <QDebug>

#include <windows.h>

class Object : public QGraphicsItem, public QObject
{

protected:
    bool flag = false;
    enum Direction{wait, wait_left, left, up_left, up, right, down, down_left};
    Direction direction = wait;

public:
    explicit Object(QObject* parent = 0);
    ~Object();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    virtual QRectF boundingRect() const = 0;

public slots:
    void slotGameTimer();
};

#endif // OBJECT_H
