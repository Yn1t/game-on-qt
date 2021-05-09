#include "object.h"

Object::Object(QObject* parent)
{
    Q_UNUSED(parent);
}

Object::~Object()
{

}

void Object::slotGameTimer()
{

    if(GetAsyncKeyState('A'))
    {
        flag = true;
        this->setX(this->x() - 1);
        this->direction = left;
    }
    else if(GetAsyncKeyState('D'))
    {
        flag = false;
        this->setX(this->x() + 1);
        this->direction = right;
    }
    else if(GetAsyncKeyState('W'))
    {
        this->setY(this->y() - 1);

        if (flag)
            this->direction = up_left;
        else
            this->direction = up;
    }
    else if(GetAsyncKeyState('S'))
    {
        this->setY(this->y() + 1);

        if (flag)
            this->direction = down_left;
        else
            this->direction = down;
     }
    else if (this->direction == left || this->direction == up_left || this->direction == down_left)
    {
        flag = true;
        this->direction = wait_left;
    }
    else if (this->direction == right || this->direction == up || this->direction == down)
    {
        flag = false;
        this->direction = wait;
    }


}

