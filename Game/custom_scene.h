#ifndef CUSTOM_SCENE_H
#define CUSTOM_SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QDebug>
#include "sprite_hero.h"

class custom_scene : public QGraphicsScene
{
public:
    explicit custom_scene(QObject* parent = 0);
    ~custom_scene();

private:
    Object* hero;
    QTimer* timer;
};

#endif // CUSTOM_SCENE_H
