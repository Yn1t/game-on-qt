#ifndef CUSTOM_SCENE_H
#define CUSTOM_SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include "sprite_hero.h"
#include "slime.h"

class custom_scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit custom_scene(QObject* parent = 0);
    ~custom_scene();
    QTimer* timer;

signals:
    void scores_inc();
    void spawn_signal();

public slots:
    void death_unit_slot();
};

#endif // CUSTOM_SCENE_H
