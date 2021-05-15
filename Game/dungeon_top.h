#ifndef DUNGEON_TOP_H
#define DUNGEON_TOP_H

#include <QPixmap>
#include <QPainter>

#include "invisible_wall.h"
#include "custom_scene.h"

class Dungeon_top : public custom_scene
{
public:
    explicit Dungeon_top(QObject* parent = 0);
    ~Dungeon_top();

private:
    QPixmap* mapImage_Dungeon;
    Static_object* walls[86];
    Essence* slime;
};

#endif // DUNGEON_TOP_H
