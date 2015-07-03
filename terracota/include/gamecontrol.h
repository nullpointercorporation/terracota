#ifndef H_GAMECONTROL_H
#define H_GAMECONTROL_H

#include <core/sprite.h>
#include <core/object.h>
#include <core/listener.h>

class Killa;
class Inti;

class GameControl: public Object, Listener
{
public:
	static GameControl* get_instance();

	Object* get_main_char();

	void draw_self();
	void update_self(unsigned long elapsed);
	void swap_char();
    bool on_event(const KeyboardEvent& event);
    bool on_event(const JoyStickEvent& event);
private:
    GameControl(Object *parent, ObjectID id);
    ~GameControl();
    Inti* m_inti; 
    Killa* m_killa;
};

extern GameControl *gc;

#endif
