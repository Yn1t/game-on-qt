#include "sprite_hero.h"

Sprite_hero::Sprite_hero(QObject* parent) : Essence(parent)
{
    type_ = 0;
    currentFrame = 0;

    this->max_health = 1000;
    this->health = max_health;
    qDebug() << this->health;

    spriteImage_wait = new QPixmap(":/dwarf_sprites/Dwarf_waiting.png");
    spriteImage_wait_left = new QPixmap(":/dwarf_sprites/Dwarf_waiting_left.png");
    spriteImage_right = new QPixmap(":/dwarf_sprites/Dwarf_walk_right.png");
    spriteImage_left = new QPixmap(":/dwarf_sprites/Dwarf_walk_left.png");
    spriteImage_up_left = new QPixmap(":/dwarf_sprites/Dwarf_walk_up_left.png");
    spriteImage_up_rigth = new QPixmap(":/dwarf_sprites/Dwarf_walk_up_right.png");
    spriteImage_down_left = new QPixmap(":/dwarf_sprites/Dwarf_walk_down_left.png");
    spriteImage_down_right = new QPixmap(":/dwarf_sprites/Dwarf_walk_down_right.png");

    spriteImage_attack_right = new QPixmap(":/dwarf_sprites/Dwarf_attack_right.png");
    spriteImage_attack_left = new QPixmap(":/dwarf_sprites/Dwarf_attack_left.png");

    spriteImage = spriteImage_wait;

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Sprite_hero::nextFrame);
    timer->start(120);
}

Sprite_hero::~Sprite_hero()
{
    timer->stop();
    delete timer;
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
    if (direction != attack_right && direction != attack_left)
    {
        currentFrame += 260;
        if (currentFrame >= 2060)
            currentFrame = 0;
        this->update(-25,-40,260,144);
    }
    else
    {
        currentFrame += 260;
        if (currentFrame >= 1500)
            currentFrame = 0;
        this->update(-25,-40,260,144);
    }

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
    else if (direction == attack_right)
    {
        spriteImage = spriteImage_attack_right;
    }
    else if (direction == attack_left)
    {
        spriteImage = spriteImage_attack_left;
    }
    else
    {
        spriteImage = spriteImage_wait;
    }
}

void Sprite_hero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-25, -40, *spriteImage, currentFrame, 0, 220, 144);
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::green);
    painter->drawRect(30,-40, (int) 150*health/max_health,10);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Sprite_hero::boundingRect() const
{
    return QRectF(-25,-40,220,144);
}

void Sprite_hero::slotGameTimer()
{
    bool flag_col = true;

    if(GetAsyncKeyState('A'))
    {
        flag = true;
        this->setX(this->x() - 1);
        this->direction = left;

        for (int i = 0; i < scene()->collidingItems(this).size(); ++i)
        {
            if (!dynamic_cast<Static_object*>(scene()->collidingItems(this).at(i)))
                flag_col = false;
        }

        if (!(scene()->collidingItems(this).size() == 1))
            flag_col = true;

        if (!scene()->collidingItems(this).isEmpty() && flag_col)
            this->setX(this->x() + 1);
    }
    else if(GetAsyncKeyState('D'))
    {
        flag = false;
        this->setX(this->x() + 1);
        this->direction = right;

        for (int i = 0; i < scene()->collidingItems(this).size(); ++i)
        {
            if (!dynamic_cast<Static_object*>(scene()->collidingItems(this).at(i)))
                flag_col = false;
        }

        if (!(scene()->collidingItems(this).size() == 1))
            flag_col = true;

        if (!scene()->collidingItems(this).isEmpty() && flag_col)
           this->setX(this->x() - 1);
    }
    else if(GetAsyncKeyState('W'))
    {
        this->setY(this->y() - 1);

        for (int i = 0; i < scene()->collidingItems(this).size(); ++i)
        {
            if (!dynamic_cast<Static_object*>(scene()->collidingItems(this).at(i)))
                flag_col = false;
        }

        if (!(scene()->collidingItems(this).size() == 1))
            flag_col = true;

        if (!scene()->collidingItems(this).isEmpty() && flag_col)
            this->setY(this->y() + 1);

        if (flag)
            this->direction = up_left;
        else
            this->direction = up;
    }
    else if(GetAsyncKeyState('S'))
    {
        this->setY(this->y() + 1);

        for (int i = 0; i < scene()->collidingItems(this).size(); ++i)
        {
            if (!dynamic_cast<Static_object*>(scene()->collidingItems(this).at(i)))
                flag_col = false;
        }

        if (!(scene()->collidingItems(this).size() == 1))
            flag_col = true;

        if (!scene()->collidingItems(this).isEmpty() && flag_col)
            this->setY(this->y() - 1);

        if (flag)
            this->direction = down_left;
        else
            this->direction = down;
     }
    else if (GetAsyncKeyState(VK_LBUTTON) && (this->direction == up \
             || this->direction == right || this->direction == this->down\
             || this->direction == this->wait))
    {
        this->direction = attack_right;

    }
    else if (GetAsyncKeyState(VK_LBUTTON) && (this->direction == up_left \
             || this->direction == left || this->direction == this->down_left\
             || this->direction == this->wait_left))
    {
        this->direction = attack_left;
    }
    else if ((this->direction == left || this->direction == up_left || this->direction == down_left \
              || this->direction == attack_left) && !GetAsyncKeyState(VK_LBUTTON))
    {
        flag = true;
        this->direction = wait_left;
    }
    else if ((this->direction == right || this->direction == up || this->direction == down \
             || this->direction == attack_right) && !GetAsyncKeyState(VK_LBUTTON))
    {
        flag = false;
        this->direction = wait;
    }

    for (int i = 0; i < scene()->collidingItems(this).size(); ++i)
    {
        if (auto obj = dynamic_cast<Essence*>(scene()->collidingItems(this).at(i)))
            if (direction == attack_left || direction == attack_right)
                {
                    obj->hit(1);
                }
    }
}

void Sprite_hero::hit(int damage)
{
    health -= damage;
    update(-25,-45,230,128);
    if (health <= 0)
    {
        emit end_game();
    }
}
