#ifndef BRIDGE_H
#define BRIDGE_H

#include <QPixmap>
#include <QPainter>
#include <QTimer>

#include "custom_scene.h"
#include "invisible_wall.h"
#include "sprite_hero.h"

class Bridge : public custom_scene
{
public:
    explicit Bridge(QObject* parent = 0);
    ~Bridge();

private:
    //QTimer* timer;
    QPixmap* mapImage_Bridge;
    Static_object* stones[96];
};

#endif // BRIDGE_H
