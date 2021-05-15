#ifndef LAVA_ROOM_H
#define LAVA_ROOM_H

#include <QPixmap>
#include <QPainter>

#include "custom_scene.h"
#include "invisible_wall.h"
#include "static_object.h"
#include "forest.h"

class Lava_room : public custom_scene
{
public:
    explicit Lava_room(QObject* parent = 0);
    ~Lava_room();

private:
    QPixmap* mapImage_LavaRoom;
    Static_object* stones[58];
    Essence* slime;
};
#endif // LAVA_ROOM_H
