#ifndef SLIME_H
#define SLIME_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QTransform>

#include "essence.h"

class Slime : public Essence
{
    Q_OBJECT
public:
    explicit Slime(QObject* parent = 0);
    ~Slime();
    void hit(int damage);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;


private:
    QTimer* timer;
    QTimer* death_timer;
    QPixmap* spriteImage;
    QPixmap* spriteImage_left;
    QPixmap* spriteImage_right;
    QPixmap* spriteImage_death;
    int currentFrame;

private slots:
    void nextFrame();
    void slotGameTimer();
};

#endif // SLIME_H
