#ifndef CUSTOM_SCENE_H
#define CUSTOM_SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QDebug>

class custom_scene : public QGraphicsScene
{
public:
    explicit custom_scene(QObject* parent = 0);
    ~custom_scene();
};

#endif // CUSTOM_SCENE_H
