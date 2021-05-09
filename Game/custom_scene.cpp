#include "custom_scene.h"

custom_scene::custom_scene(QObject* parent) : QGraphicsScene()
{
    hero = new Sprite_hero();
    this->addItem(hero);

    hero->setPos(0, 540);


    timer = new QTimer();
    connect(timer, &QTimer::timeout, hero, &Sprite_hero::slotGameTimer);
    timer->start(1000/500);

    Q_UNUSED(parent);
}

custom_scene::~custom_scene()
{
    delete hero;
}
