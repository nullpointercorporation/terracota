#include "gamecontrol.h"

#include <core/eventsmanager.h>
#include <core/joystickevent.h>
#include <core/keyboardevent.h>
#include <core/level.h>

#include "ui.h"
#include "inti.h"
#include "killa.h"
#include "life.h"

#include <iostream>
using namespace std;

static GameControl* m_instance = NULL;

GameControl*
GameControl::get_instance(){
	if (m_instance == NULL){
		m_instance = new GameControl(NULL,"gamecontrol");
	}
	return m_instance;
}

GameControl::GameControl(Object* parent, ObjectID id)
	: Object(parent,id), m_inti(nullptr),m_killa(nullptr), m_level(nullptr)
{
	m_inti = new Inti(this,"inti");
    m_killa = new Killa(this,"killa");

    m_killa->set_active(false);
    m_killa->set_visible(false);


    Interface *ui = new Interface(this, "ui", this);

    add_child(ui);
	add_child(m_inti);
	add_child(m_killa);

    Environment *env = Environment::get_instance();
    env->events_manager->register_listener(this);
}

void 
GameControl::set_char_position(double x,double y)
{
	m_inti->set_position(x,y);
    m_killa->set_position(x,y);
}

Level*
GameControl::level()
{
	return m_level;
}


void
GameControl::set_level(Level* level)
{
	m_level = level;
}

GameControl::~GameControl()
{
    delete m_inti;
    delete m_killa;
    Environment *env = Environment::get_instance();
    env->events_manager->unregister_listener(this);
}

Inti* 
GameControl::get_inti(){
	return m_inti;
}

Killa*
GameControl::get_killa(){
	return m_killa;
}

Object*
GameControl::get_main_char()
{
    if (m_inti->active())
        return m_inti;
	return m_killa;
}

void
GameControl::swap_char(){
    if (m_inti->active() and m_inti->state_id() == Inti::IDLE)
    {
        m_inti->set_active(false);  
        m_inti->set_visible(false);
        m_killa->set_active(true);
        m_killa->set_visible(true);
        m_killa->set_position( m_inti->x(),m_inti->y());

        if (  m_inti->direction() == Inti::LEFT  )
            m_killa->set_direction(Killa::LEFT);
        else
            m_killa->set_direction(Killa::RIGHT);

    }
    else if (m_killa->active() and m_killa->state_id() == Killa::IDLE)
    {
        m_inti->set_active(true);  
        m_inti->set_visible(true);
        m_killa->set_active(false);
        m_killa->set_visible(false);
        m_inti->set_position( m_killa->x(),m_killa->y());
        if (  m_killa->direction() == Killa::LEFT )
            m_inti->set_direction(Inti::LEFT);
        else
            m_inti->set_direction(Inti::RIGHT);
    }
}

void 
GameControl::draw_self()
{
}

void 
GameControl::update_self(unsigned long elapsed)
{
    if (  m_inti->life()->life() <= 0     )
    {
        level()->set_next("gameover");
        level()->finish();
    }
}


bool 
GameControl::on_event(const KeyboardEvent& event)
{
	switch (event.state())
	{
	case KeyboardEvent::PRESSED:
		switch (event.key())
		{
		default:
			break;
		}
		break;

	case KeyboardEvent::RELEASED:
		switch (event.key())
		{
		case KeyboardEvent::C:
			swap_char();
			return true;
		default:
			break;
		}
		break;
	}
	return false;
}

bool 
GameControl::on_event(const JoyStickEvent& event)
{
	switch (event.state())
	{
	case JoyStickEvent::PRESSED:
		switch (event.button())
		{
		default:
			break;
		}
		break;

	case JoyStickEvent::RELEASED:
		switch (event.button())
		{
		case JoyStickEvent::TRIANGLE:
			swap_char();
			return true;
		default:
			break;
		}
		break;
	}
	return false;
}
