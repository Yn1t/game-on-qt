#include "slime.h"

Slime::Slime(QObject *parent) : Essence(parent)
{
    type_ = 1;
    currentFrame = 0;
    spriteImage_left = new QPixmap(":/slime_sprites/slime-Sheet.png");
    spriteImage_right = new QPixmap(":/slime_sprites/slime-Sheet_right.png");
    spriteImage_death = new QPixmap(":/slime-sprites.slime_death.png");

    spriteImage = spriteImage_right;

    max_health = 1000;
    health = max_health;

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Slime::nextFrame);
    timer->start(120);
}

Slime::~Slime()
{
    delete spriteImage_left;
    delete spriteImage_right;
    delete timer;
}

void Slime::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-25, -40, *spriteImage, currentFrame, 0, 260, 134);
    painter->setBrush(Qt::red);
    painter->drawRect(30,-40, (int) 150*health/max_health,10);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Slime::boundingRect() const
{
    return QRectF(-25,-40,260,128);
}

void Slime::nextFrame()
{
    currentFrame += 260;
    if (currentFrame >= 2080)
        currentFrame = 0;
    this->update(-25,-40,260,128);

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
        spriteImage = spriteImage_left;
    }
    else if (direction == up)
    {
        spriteImage = spriteImage_right;
    }
    else if (direction == down_left)
    {
        spriteImage = spriteImage_left;
    }
    else if (direction == down)
    {
        spriteImage = spriteImage_right;
    }
    else if (direction == wait_left)
    {
        spriteImage = spriteImage_left;
    }
    else
    {
        spriteImage = spriteImage_right;
    }

}

void Slime::slotGameTimer()
{
   flag = true;

   for (int i = 0; i < scene()->items().size(); ++i)
   {
        if (auto obj = dynamic_cast<Essence*>(scene()->items().at(i)))
        {
            if (obj->x() > this->x())
            {
                this->setX(this->x() + 1);
                this->direction = right;
            }
            else if (obj->x() < this->x())
            {
                this->setX(this->x() - 1);
                this->direction = left;
            }
            else if (obj->y() > this->y())
            {
                this->setY(this->y() + 1);
            }
            else if (obj->y() < this->y())
            {
                this->setY(this->y() - 1);
            }

             flag = false;
        }
    }

    if (flag)
    {
        if (this->x() < this->x_spawn)
            this->setX(this->x() + 1);
        else if (this->x() > this->x_spawn)
            this->setX(this->x() - 1);
        if (this->y() < this->y_spawn)
            this->setY(this->y() + 1);
        else if (this->y() > this->y_spawn)
            this->setY(this->y() - 1);
    }


    for (int i = 0; i < scene()->collidingItems(this).size(); ++i)
    {
        if (auto obj = dynamic_cast<Essence*>(scene()->collidingItems(this).at(i)))
        {
            obj->hit(1);
            if (!obj)
                emit end_game();
        }
    }
}

void Slime::hit(int damage)
{
    health -= damage;
    update(-25,-45,230,128);
    if (health <= 0)
    {
        this->deleteLater();
        emit death_signal();
    }
}

