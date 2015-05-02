#ifndef H_CHARACTER_H
#define H_CHARACTER_H

#include "object.h"
#include "keyboardeventlistener.h"
#include "joystickeventlistener.h"

class Animation;

class Character : public Object, KeyboardEventListener, JoyStickEventListener
{
public:
	Character(Object* parent = nullptr,ObjectID id = "" );
    virtual ~Character();	
	void set_animation(Animation* animation);
	void set_speed(double x, double y);
	double speed_x();
	double speed_y();
	bool onKeyboardEvent(const KeyboardEvent& event);
	bool onJoyStickEvent(const JoyStickEvent& event);
	void draw_self();
	void update_self(unsigned long elapsed);
private:
	Animation* m_animation;
	double speed[2];
	double m_speed_x;
	double m_speed_y;
	unsigned long m_last;
};

#endif
