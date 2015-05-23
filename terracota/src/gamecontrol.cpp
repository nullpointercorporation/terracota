#include "gamecontrol.h"

#include <core/keyboardevent.h>
#include <core/mousebuttonevent.h>
#include <core/mousemotionevent.h>
#include <core/joystickevent.h>
#include "inti.h"


GameControl::GameControl(Object *parent, ObjectID id)
	: Object(parent,id), m_inti(nullptr),m_inti2(nullptr) 
{
	m_inti = new Inti(this,"inti");
	m_inti2 = new Inti(this,"inti2");
	m_inti2->set_position(200,300);
	m_inti->set_position(0,300);
	add_child(m_inti);
	add_child(m_inti2);
}

GameControl::~GameControl()
{
}

bool 
GameControl::onKeyboardEvent(const KeyboardEvent& event)
{
	switch(event.state())
	{
		case KeyboardEvent::PRESSED:
			switch(event.key())
			{
				case KeyboardEvent::ESCAPE:
					
					return true;
			}
	}

	return false;
}
bool 
GameControl::onMouseButtonEvent(const MouseButtonEvent& event)
{
	return false;
}
bool 
GameControl::onMouseMotionEvent(const MouseMotionEvent& event)
{
	return false;
}
bool 
GameControl::onJoyStickEvent(const JoyStickEvent& event)
{
	return false;
}
