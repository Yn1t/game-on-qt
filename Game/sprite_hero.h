#ifndef SPRITE_HERO_H
#define SPRITE_HERO_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QTransform>

#include "object.h"

class Sprite_hero : public Object
{
    Q_OBJECT
public:
    explicit Sprite_hero(QObject* parent = 0);
    ~Sprite_hero();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

private:
    QTimer* timer;
    QPixmap* spriteImage;
    QPixmap* spriteImage_wait;
    QPixmap* spriteImage_wait_left;
    QPixmap* spriteImage_right;
    QPixmap* spriteImage_left;
    QPixmap* spriteImage_up;
    QPixmap* spriteImage_down_left;
    QPixmap* spriteImage_down_right;
    QPixmap* spriteImage_up_rigth;
    QPixmap* spriteImage_up_left;
    int currentFrame;

private slots:
    void nextFrame();
};

#endif // SPRITE_HERO_H
