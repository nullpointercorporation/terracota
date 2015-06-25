#ifndef BAT_H
#define BAT_H

#include <core/object.h>
#include <core/animation.h>

#include "memory.h"


class Bat : public Object
{
public:
    Bat(Object* object, ObjectID id);
    ~Bat();

    void draw_self();
    void update_self(unsigned long elapsed);
private:
    unique_ptr<Animation> m_animation;
};



#endif


