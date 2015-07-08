#ifndef UI_H
#define UI_H

#include <core/object.h>
#include <core/environment.h>
#include <core/rect.h>
#include <memory>

#include "gamecontrol.h"

using std::shared_ptr;

class Interface : public Object
{
public:
    Interface(Object * parent,ObjectID id,GameControl* gc);
    void draw_self();
    void update_self(unsigned long elepsed);

private:
    shared_ptr<Texture> ui_elements;
	Rect m_killa,m_inti,m_button,m_life_bar;
    GameControl* m_gc;
};


#endif
