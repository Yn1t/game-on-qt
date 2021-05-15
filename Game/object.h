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

#include <static_object.h>
#include <invisible_wall.h>

#include <math.h>
#pragma comment(lib, "User32.lib")

class Object : public QObject, public QGraphicsItem
{
protected:
    bool flag = false;
    enum Direction{wait, wait_left, left, up_left, up, right, down, down_left, attack_right, attack_left};
    Direction direction = wait;
    int max_health;
    int health;
    int type;

public:
    explicit Object(QObject* parent = 0);
    ~Object();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    virtual QRectF boundingRect() const = 0;
    virtual void hit(int damage);

public slots:
    virtual void slotGameTimer();

signals:
    //void end_game();
    //void death_signal();
};

#endif // OBJECT_H
