#ifndef BRIDGE_H
#define BRIDGE_H

#include <QPixmap>
#include <QPainter>

#include "custom_scene.h"

class Bridge : public custom_scene
{
public:
    Bridge(QObject* parent = 0);
    ~Bridge();

private:
    QPixmap* mapImage_Bridge;
};

#endif // BRIDGE_H
