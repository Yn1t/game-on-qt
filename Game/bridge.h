#ifndef BRIDGE_H
#define BRIDGE_H

#include <QPixmap>
#include <QPainter>

#include "custom_scene.h"
#include "invisible_wall.h"
#include "static_object.h"

class Bridge : public custom_scene
{
public:
    explicit Bridge(QObject* parent = 0);
    ~Bridge();

private:
    QPixmap* mapImage_Bridge;
    Static_object* stones[96];
};

#endif // BRIDGE_H
