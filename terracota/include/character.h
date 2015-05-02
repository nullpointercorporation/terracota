#ifndef H_CHARACTER_H
#define H_CHARACTER_H

#include "object.h"
#include "rect.h"
#include "keyboardeventlistener.h"
#include "joystickeventlistener.h"

class Image;

class Character : public Object, KeyboardEventListener, JoyStickEventListener
{
public:
	Character(Object* parent = nullptr,ObjectID id = "" ,
			  const string& sprites = "",int w = 40 ,int h = 100 );
    virtual ~Character();	

	void set_speed(double x, double y);
	double speed_x();
	double speed_y();
	bool onKeyboardEvent(const KeyboardEvent& event);
	bool onJoyStickEvent(const JoyStickEvent& event);
private:
	Image* m_sprites;
	Rect m_clip;
	void draw_self();
	void update_self(unsigned long elapsed);
	double speed[2];
	double m_speed_x;
	double m_speed_y;
	unsigned long m_last;
};

#endif
