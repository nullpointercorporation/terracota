#include "character.h"
#include "keyboardevent.h"
#include "environment.h"
#include "rect.h"

Character::Character(Object* parent, ObjectID id,Animation* animation_idle,Animation* animation_running)
	: Object(parent,id),m_animation_idle(nullptr), m_animation_running(nullptr),m_speed_x(0.0),m_speed_y(0.0),m_last(0)
{
    Environment* env  = Environment::get_instance();
    env->events_manager->register_keyboard_event_listener(this);
	m_animation_idle = animation_idle;
	m_animation_running = animation_running;
	
}
Character::~Character()
{
    Environment* env  = Environment::get_instance();
    env->events_manager->unregister_keyboard_event_listener(this);
}

bool 
Character::onKeyboardEvent(const KeyboardEvent& event)
{
    switch (event.state())
    {
        case KeyboardEvent::PRESSED:
        switch (event.key())
        {
        case KeyboardEvent::LEFT:
                m_speed_x = -1; 
                return true;

            case KeyboardEvent::RIGHT:
                m_speed_x = 1;
                return true;
			case KeyboardEvent::UP:
				m_speed_y = -1;
				break;
			case KeyboardEvent::DOWN:
				m_speed_y = 1;
				break;
            default:
                return false;
        }

        case KeyboardEvent::RELEASED:
        switch (event.key())
        {
            case KeyboardEvent::LEFT:
            case KeyboardEvent::RIGHT:
                m_speed_x = 0;
                return true;
			case KeyboardEvent::UP:
			case KeyboardEvent::DOWN:
				m_speed_y = 0;
				return true;
            default:
                return false;
        }

        default:
            break;
    }
    return false;
}

void 
Character::draw_self()
{
	if(  m_speed_x == 0  )
	{
		m_animation_idle->draw(x(),y());
	}else{
		m_animation_running->draw(x(),y());
	}
}

void 
Character::update_self(unsigned long elapsed)
{
	m_animation_idle->update(elapsed);
	if (  ( m_speed_x + m_speed_y   ) == 0   )
	{
			m_last = 0;
			return;
	}

	if (not m_last)  m_last = elapsed;
	Environment* env = Environment::get_instance();

	if (m_speed_x != 0)
	{
		double x =  this->x() + m_speed_x*((elapsed - m_last)/1000.0);
		if(x) this->set_x(x);
		if (m_speed_x > 0){
			m_animation_running->set_row(0);
		}else if(m_speed_x < 0){
			m_animation_running->set_row(1);
		}
	}	
	if (m_speed_y != 0)
	{
		double y =  this->y() + m_speed_x*((elapsed - m_last)/1000.0);
		if(y) this->set_y(y);
	}
}
