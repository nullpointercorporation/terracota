#include "gamecontrol.h"

#include "ui.h"
#include "inti.h"
#include "killa.h"

GameControl::GameControl(Object* parent, ObjectID id)
	: Object(parent,id), m_inti(nullptr),m_killa(nullptr),m_main_char(nullptr)
{
	m_inti = new Inti(this,"inti");
    m_killa = new Killa(this,"killa");
    m_main_char = m_inti;

	m_inti->set_position(0,0);
    m_killa->set_position(0,0);

    Interface *ui = new Interface(nullptr,"ui",this);

    add_child(ui);
	add_child(m_inti);
	add_child(m_killa);
}

GameControl::~GameControl()
{
    delete m_inti;
    delete m_killa;
    delete m_main_char;
}

Inti*
GameControl::get_main_char()
{
	return (Inti*)m_main_char;
}


void 
GameControl::draw_self()
{
}

void 
GameControl::update_self(unsigned long elapsed)
{
}

