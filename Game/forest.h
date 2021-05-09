#ifndef FOREST_H
#define FOREST_H


#include <QPixmap>
#include <QPainter>

#include "custom_scene.h"
#include "invisible_wall.h"
#include "static_object.h"

class Forest : public custom_scene
{
public:
    explicit Forest(QObject* parent = 0);
    ~Forest();

private:
    QPixmap* mapImage_Forest;
    Static_object* invisible_tree[250];
};

#endif // FOREST_H
