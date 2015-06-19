#ifndef H_GAMECONTROL_H
#define H_GAMECONTROL_H

#include <core/sprite.h>
#include <core/object.h>

class Killa;
class Inti;

class GameControl: public Object
{
public:
    GameControl(Object *parent, ObjectID id);
    ~GameControl();

	Inti* get_main_char();

	void draw_self();
	void update_self(unsigned long elapsed);

private:
    Inti* m_inti; 
    Killa* m_killa;
	Object* m_main_char;
};

#endif
