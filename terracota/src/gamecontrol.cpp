#include "gamecontrol.h"

#include <core/eventsmanager.h>
#include <core/joystickevent.h>
#include <core/keyboardevent.h>

#include "ui.h"
#include "inti.h"
#include "killa.h"
#include "bat.h"

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
	: Object(parent,id), m_inti(nullptr),m_killa(nullptr)
{
	m_inti = new Inti(this,"inti");
    m_killa = new Killa(this,"killa");

    m_killa->set_active(false);

	m_inti->set_position(1000,460);
    m_killa->set_position(300,200);

    Interface *ui = new Interface(this, "ui", this);

    add_child(ui);
	add_child(m_inti);
	add_child(m_killa);

    Environment *env = Environment::get_instance();
    env->events_manager->register_listener(this);
}

GameControl::~GameControl()
{
    delete m_inti;
    delete m_killa;
    Environment *env = Environment::get_instance();
    env->events_manager->unregister_listener(this);
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
    if (m_inti->active() and m_inti->can_change())
    {
        m_inti->set_active(false);  
        m_killa->set_active(true);
    }
    else if (m_killa->active() and m_killa->can_change())
    {
        m_inti->set_active(true);  
        m_killa->set_active(false);
    }
}

void 
GameControl::draw_self()
{
}

void 
GameControl::update_self(unsigned long elapsed)
{
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
