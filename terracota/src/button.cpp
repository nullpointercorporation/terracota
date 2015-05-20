#include "button.h"
#include <core/rect.h>
#include <core/color.h>
#include <core/environment.h>
#include <core/mousebuttonevent.h>
#include <core/mousemotionevent.h>

#include <cstdio>


MessageID Button::clickedID = "clicked()";

Button::Button(Object* parant, ObjectID id, const string& image,
			   double x, double y, double w, double h)
	: Object(parant, id, x, y, w, h), m_image(nullptr)
{
	Environment* env  = Environment::get_instance();
	env->events_manager->register_mouse_button_event_listener(this);
	env->events_manager->register_mouse_motion_event_listener(this);
	
	m_image = env->resources_manager->get_texture(image);
	m_state = IDLE;

}

Button::~Button()
{
	Environment* env  = Environment::get_instance();
	env->events_manager->unregister_mouse_button_event_listener(this);
	env->events_manager->unregister_mouse_motion_event_listener(this);
}

void 
Button::draw_self()
{
	Environment* env = Environment::get_instance();

	if ( m_state == IDLE  )
		env->canvas->draw(m_image.get(),Rect(0,0,w(),h()) ,x(),y());
	if ( m_state == ON_HOVER)
		env->canvas->draw(m_image.get(),Rect(0,h(),w(),h()),x(),y());
	
}

bool
Button::onMouseButtonEvent(const MouseButtonEvent& event)
{
	if( m_state != HIDE and
	   event.state()  == MouseButtonEvent::PRESSED and
	   event.button() == MouseButtonEvent::LEFT    and
	   bounding_box().contains(event.x(), event.y()) )
	{
		char coords[64];

		notify(clickedID,coords);
		return true;
	}
	return false;
}

bool
Button::onMouseMotionEvent(const MouseMotionEvent& event)
{
	if (m_state == HIDE) return false;
	if ( bounding_box().contains(event.x(),event.y()))
	{
		m_state = ON_HOVER;
		return true;
	}
	m_state = IDLE;
	return false;
}

void 
Button::set_hide()
{
	m_state = HIDE;
}
void
Button::set_show()
{
	m_state = IDLE;
}
