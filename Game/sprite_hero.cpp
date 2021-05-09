#include "sprite_hero.h"

Sprite_hero::Sprite_hero(QObject* parent) : Object(parent)
{
    currentFrame = 0;

    spriteImage_wait = new QPixmap(":/dwarf_sprites/Dwarf_waiting.png");
    spriteImage_wait_left = new QPixmap(":/dwarf_sprites/Dwarf_waiting_left.png");
    spriteImage_right = new QPixmap(":/dwarf_sprites/Dwarf_walk_right.png");
    spriteImage_left = new QPixmap(":/dwarf_sprites/Dwarf_walk_left.png");
    spriteImage_up_left = new QPixmap(":/dwarf_sprites/Dwarf_walk_up_left.png");
    spriteImage_up_rigth = new QPixmap(":/dwarf_sprites/Dwarf_walk_up_right.png");
    spriteImage_down_left = new QPixmap(":/dwarf_sprites/Dwarf_walk_down_left.png");
    spriteImage_down_right = new QPixmap(":/dwarf_sprites/Dwarf_walk_down_right.png");

    spriteImage = spriteImage_wait;

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Sprite_hero::nextFrame);
    timer->start(120);
}

Sprite_hero::~Sprite_hero()
{
    delete spriteImage;
    delete spriteImage_wait;
    delete spriteImage_wait_left;
    delete spriteImage_right;
    delete spriteImage_left;
    delete spriteImage_up_left;
    delete spriteImage_up_rigth;
    delete spriteImage_down_right;
    delete spriteImage_down_left;
}

void Sprite_hero::nextFrame()
{
    currentFrame += 260;
    if (currentFrame >= 2080)
        currentFrame = 0;
    this->update(-25,-40,340,144);

    if (direction == right)
    {
        spriteImage = spriteImage_right;
    }
    else if (direction == left)
    {
        spriteImage = spriteImage_left;
    }
    else if (direction == up_left)
    {
        spriteImage = spriteImage_up_left;
    }
    else if (direction == up)
    {
        spriteImage = spriteImage_up_rigth;
    }
    else if (direction == down_left)
    {
        spriteImage = spriteImage_down_left;
    }
    else if (direction == down)
    {
        spriteImage = spriteImage_up_rigth;
    }
    else if (direction == wait_left)
    {
        spriteImage = spriteImage_wait_left;
    }
    else
    {
        spriteImage = spriteImage_wait;
    }
}

void Sprite_hero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-25, -40, *spriteImage, currentFrame, 0, 260, 144);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Sprite_hero::boundingRect() const
{
    return QRectF(-25,-40,260,144);
}
