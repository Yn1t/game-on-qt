

#include "bridge.h"

Bridge::Bridge(QObject* parent) : custom_scene(parent)
{
    mapImage_Bridge = new QPixmap(":/scene_sprites/bridge.png");
    this->setBackgroundBrush(*mapImage_Bridge);
}

Bridge::~Bridge()
{
    delete mapImage_Bridge;
}
