#include "dungeon_top.h"

Dungeon_top::Dungeon_top(QObject* parent) : custom_scene(parent)
{
    mapImage_Dungeon = new QPixmap(":/scene_sprites/dungeon_1.1.png");
    this->setBackgroundBrush(*mapImage_Dungeon);
    for (int i = 0; i < 86; i++)
    {
        this->walls[i] = new Invisible_wall(this);
        this->addItem(walls[i]);
    }
    slime = new Slime();
    this->addItem(slime);
    slime->x_spawn = 900;
    slime->y_spawn = 540;

    slime->setPos(slime->x_spawn, slime->y_spawn);

    connect(slime, &Slime::death_signal, this, &custom_scene::death_unit_slot);
    connect(timer, &QTimer::timeout, slime, &Essence::slotGameTimer);

    int x = 700, y = 150, i = 0;

    for (i = 0; i < 11; ++i, x += 40)
        walls[i]->setPos(x, y);

    for (i = 11, y = 60, x = 640; i < 22; ++i, x  -= 40, y += 40)
        walls[i]->setPos(x, y);

    for (i = 22, y = 60, x = 1140; i < 38; ++i, x += 40, y += 40)
        walls[i]->setPos(x, y);

    for (i = 38, x = 230, y = 500; i < 50; ++i, y += 40)
        walls[i]->setPos(x, y);

    for (i = 50, x = 1680, y = 700; i < 62; ++i, y += 40)
        walls[i]->setPos(x, y);

    for (i = 62, x = 240, y = 1080; i < 74; ++i, x += 40)
        walls[i]->setPos(x, y);

    for (i = 74, x = 1690, y = 1080; i < 86; ++i, x -= 40)
        walls[i]->setPos(x, y);
}

Dungeon_top::~Dungeon_top()
{
    //timer->stop();
    //delete timer;
    delete this->mapImage_Dungeon;
    for (int i = 0; i < 86; ++i)
        delete this->walls[i];
}


