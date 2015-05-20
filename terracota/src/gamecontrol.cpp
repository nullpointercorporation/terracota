#include "gamecontrol.h"

#include <core/keyboardevent.h>
#include <core/mousebuttonevent.h>
#include <core/mousemotionevent.h>
#include <core/joystickevent.h>
#include "inti.h"


GameControl::GameControl(Object *parent, ObjectID id)
	: Object(parent,id), m_inti(nullptr) 
{
	m_inti = new Inti(this,"inti");
	m_inti->set_position(0,300);
	add_child(m_inti);
}

GameControl::~GameControl()
{
}

bool 
GameControl::onKeyboardEvent(const KeyboardEvent& event)
{

	return m_inti->onKeyboardEvent(event);
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
