#ifndef CHARACTER_H
#define CHARACTER_H

#include "object.h"
#include "keyboardeventlistener.h"
#include "animation.h"



class Character: public Object, KeyboardEventListener
{
public:
    Character(Object* parent, ObjectID id="",Animation* animation_idle = nullptr,Animation* animation_running = nullptr);
    ~Character();

    bool onKeyboardEvent(const KeyboardEvent& event);

private:
    Animation* m_animation_idle;
    Animation* m_animation_running;
    double m_speed_x,m_speed_y;
    unsigned long m_last;
    void draw_self();
    void update_self(unsigned long elapsed);
};

#endif
