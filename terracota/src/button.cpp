#include "button.h"
#include "rect.h"
#include "color.h"
#include "environment.h"
#include "mousebuttonevent.h"

#include <cstdio>

class Button::Impl
{
public:
	Impl(const Color& bg) : background(bg) {}
	Color background;
};

MessageID Button::clickedID = "clicked()";

Button::Button(Object* parant, ObjectID id, 
			   double x, double y, double w, double h,
			   const Color& background)
	: Object(parant, id, x, y, w, h), m_impl(new Impl(background))
{
	Environment* env  = Environment::get_instance();
	env->events_manager->register_mouse_button_event_listener(this);
}

Button::~Button()
{
	Environment* env  = Environment::get_instance();
	env->events_manager->unregister_mouse_button_event_listener(this);
}

void 
Button::draw_self()
{
	Environment* env = Environment::get_instance();
	env->canvas->fill(bounding_box(),m_impl->background);
}

bool
Button::onMouseButtonEvent(const MouseButtonEvent& event)
{
	if(event.state()  == MouseButtonEvent::PRESSED and
	   event.button() == MouseButtonEvent::LEFT    and
	   bounding_box().contains(event.x(), event.y()) )
	{
		char coords[64];
		sprintf(coords, "%.2f,%.2f", event.x(),event.y());

		notify(clickedID,coords);
		return true;
	}
	return false;
}
