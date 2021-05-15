

#include "bridge.h"

Bridge::Bridge(QObject* parent) : custom_scene(parent)
{
    mapImage_Bridge = new QPixmap(":/scene_sprites/bridge_2.png");
    this->setBackgroundBrush(*mapImage_Bridge);

    int j = 0;
    int i = 0;

    for (int i = 0; i < 96; ++i)
    {
        stones[i] = new Invisible_wall(this);
        this->addItem(stones[i]);
    }

    for (i = 0; i < 48; j += 40, ++i)
        stones[i]->setPos(j, 280);

    for (j = 0; i < 96; j += 40, ++i)
        stones[i]->setPos(j, 690);
}

Bridge::~Bridge()
{
    delete mapImage_Bridge;

    for (int i = 0; i < 96; ++i)
        delete stones[i];
}
