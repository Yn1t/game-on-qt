#ifndef ESSENCE_H
#define ESSENCE_H

#include <QDebug>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QPixmap>
#include <QPainter>

#include "invisible_wall.h"

#include "windows.h"



class Essence : public QObject, public QGraphicsItem
{
    Q_OBJECT
protected:
    bool flag = false;
    enum Direction{wait, wait_left, left, up_left, up, right, down, down_left, attack_right, attack_left};
    Direction direction = wait;

signals:
    void end_game();
    void death_signal();

public:
    explicit Essence(QObject* parent = 0);
    ~Essence();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    virtual QRectF boundingRect() const = 0;
    virtual void hit(int damage) = 0;
    int type_ = 1;
    int max_health;
    int health;
    int x_spawn;
    int y_spawn;

public slots:
    virtual void slotGameTimer();
};

#endif // ESSENCE_H
