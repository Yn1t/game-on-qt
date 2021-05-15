#include "custom_scene.h"

custom_scene::custom_scene(QObject* parent) : QGraphicsScene()
{
    timer = new QTimer();
    timer->start(5);
    Q_UNUSED(parent);
}

custom_scene::~custom_scene()
{
    timer->stop();
    delete timer;
}

void custom_scene::death_unit_slot()
{
    emit scores_inc();
}

