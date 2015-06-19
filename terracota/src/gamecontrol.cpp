#include "gamecontrol.h"

#include "inti.h"
#include "ui.h"

GameControl::GameControl(Object* parent, ObjectID id)
	: Object(parent,id), m_inti(nullptr)
{
	m_inti = new Inti(this,"inti");
	m_inti->set_position(0,0);

    Interface *ui = new Interface(nullptr,"ui",this);

    add_child(ui);
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

void 
GameControl::draw_self()
{
}
void 
GameControl::update_self(unsigned long elapsed)
{
}

