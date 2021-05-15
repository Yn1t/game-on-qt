#include "lava_room.h"

Lava_room::Lava_room(QObject* parent) : custom_scene(parent)
{
    mapImage_LavaRoom = new QPixmap(":/scene_sprites/lava_room_3.png");
    this->setBackgroundBrush(*mapImage_LavaRoom);

    int j = 0;
    int i = 0;

    slime = new Slime();
    this->addItem(slime);
    slime->x_spawn = 1100;
    slime->y_spawn = 540;

    slime->setPos(slime->x_spawn, slime->y_spawn);

    //timer = new QTimer();
    connect(slime, &Slime::death_signal, this, &custom_scene::death_unit_slot);
    connect(timer, &QTimer::timeout, slime, &Essence::slotGameTimer);
    //timer->start(15);

    for (int i = 0; i < 58; ++i)
    {
        stones[i] = new Invisible_wall(this);
        this->addItem(stones[i]);
    }

    for (j = 960, i = 0; i < 24; j += 40, ++i)
        stones[i]->setPos(j, 280);

    for (j = 960; i < 48; j += 40, ++i)
        stones[i]->setPos(j, 690);

    for (j = 280; i < 58; j += 40, ++i)
        stones[i]->setPos(840, j);
}

Lava_room::~Lava_room()
{
    delete mapImage_LavaRoom;

    for (int i = 0; i < 58; ++i)
        delete stones[i];
}
