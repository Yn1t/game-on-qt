#include "forest.h"

Forest::Forest(QObject* parent) : custom_scene(parent)
{
    mapImage_Forest = new QPixmap(":/scene_sprites/forest.png");
    this->setBackgroundBrush(*mapImage_Forest);

    for (int i = 0; i < 256; ++i)
    {
        invisible_tree[i] = new Invisible_wall(this);
        this->addItem(invisible_tree[i]);
    }

    int i = 0, j = 0;

    for (i = 0; i < 36; j += 40, ++i)
    {
        invisible_tree[i]->setPos(j, 0);
        i += 1;
        invisible_tree[i]->setPos(j, 40);
    }

    for (j = 1250; i < 72; j += 40, ++i)
    {
        invisible_tree[i]->setPos(j, 0);
        i += 1;
        invisible_tree[i]->setPos(j, 40);
    }

    for (j = 80; i < 80; j += 40, ++i)
    {
        invisible_tree[i]->setPos(0, j);
        i += 1;
        invisible_tree[i]->setPos(40, j);
    }

    for (j = 0; i < 86; j += 40, ++i)
    {
        invisible_tree[i]->setPos(1900, j);
    }

   for (j = 0; i < 158; j += 40, ++i)
    {
        invisible_tree[i]->setPos(j, 920);
        i += 1;
        invisible_tree[i]->setPos(j, 960);
        i += 1;
        invisible_tree[i]->setPos(j, 1000);
        i += 1;
        invisible_tree[i]->setPos(j, 1040);
    }

    for (j = 1250; i < 230; j += 40, ++i)
    {
        invisible_tree[i]->setPos(j, 910);
        i += 1;
        invisible_tree[i]->setPos(j, 950);
        i += 1;
        invisible_tree[i]->setPos(j, 990);
        i += 1;
        invisible_tree[i]->setPos(j, 1030);
    }

    for (j = 690; i < 240; j += 40, ++i)
    {
        invisible_tree[i]->setPos(-10, j);
        i += 1;
        invisible_tree[i]->setPos(30, j);

    }

    for (j = 690; i < 246; j += 40, ++i)
    {
        invisible_tree[i]->setPos(1900, j);
        i += 1;
        invisible_tree[i]->setPos(1940, j);
    }

    for (j = 820; i < 250; j += 40, ++i)
    {
        invisible_tree[i]->setPos(1840, j);
        i += 1;
        invisible_tree[i]->setPos(1880, j);
    }

    for (j = 240; i < 254; j += 40, ++i)
    {
        invisible_tree[i]->setPos(0, j);
        i += 1;
        invisible_tree[i]->setPos(40, j);
    }

    for (j = 240; i < 256; j += 40, ++i)
    {
        invisible_tree[i]->setPos(1900, j);
    }
}

Forest::~Forest()
{
    delete mapImage_Forest;
    //timer->stop();
    //delete timer;

    for (int i = 0; i < 256; ++i)
        delete invisible_tree[i];
}


