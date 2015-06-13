#include "gamecontrol.h"

#include "inti.h"


GameControl::GameControl(Object *parent, ObjectID id)
	: Object(parent,id), m_inti(nullptr)
{
	m_inti = new Inti(this,"inti");
	m_inti->set_position(1550,400);
	add_child(m_inti);
}

GameControl::~GameControl()
{
}

Inti*
GameControl::get_main_char()
{
	return m_inti;
}


