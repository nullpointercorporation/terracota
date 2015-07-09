#ifndef H_GAMECONTROL_H
#define H_GAMECONTROL_H

#include <core/sprite.h>
#include <core/object.h>
#include <core/listener.h>
#include <core/level.h>

class Killa;
class Inti;

class GameControl: public Object, Listener
{
public:
	static GameControl* get_instance();

	Object* get_main_char();

	void draw_self();

	Inti* get_inti();
	Killa* get_killa();
	void update_self(unsigned long elapsed);
	void swap_char();
    bool on_event(const KeyboardEvent& event);
    bool on_event(const JoyStickEvent& event);
	Level* level();
	void set_level(Level* level);
private:
    GameControl(Object *parent, ObjectID id);
    ~GameControl();
    Inti* m_inti; 
    Killa* m_killa;
	Level* m_level;
};

extern GameControl *gc;

#endif
