#ifndef H_GAMECONTROL_H
#define H_GAMECONTROL_H

#include <core/sprite.h>

#include <core/object.h>

class Inti;

class GameControl: public Object
{
public:
    GameControl(Object *parent, ObjectID id);
    ~GameControl();

	Inti* get_main_char();

private:
    Inti* m_inti; 
};

#endif
