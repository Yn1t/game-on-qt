#ifndef SPRITE_HERO_H
#define SPRITE_HERO_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QTransform>

#include "essence.h"

class Sprite_hero : public Essence
{
    Q_OBJECT
public:
    explicit Sprite_hero(QObject* parent = 0);
    ~Sprite_hero();
    void hit(int damage);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    int health;
    int max_health;

public slots:
    void slotGameTimer();

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

    QPixmap* spriteImage_attack_right;
    QPixmap* spriteImage_attack_left;
    int currentFrame;

private slots:
    void nextFrame();

signals:
};

#endif // SPRITE_HERO_H
