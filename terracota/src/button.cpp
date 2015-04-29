#include "button.h"
#include "image.h"
#include "environment.h"

#include <iostream>

using namespace std;

Button::Button(const string& id, Object * parent,
			   double x, double y, double w, double h,
			   const string& idle_image, 
			   const string& on_hover_image, 
			   const string& selected_image)
	: Rect(x,y,w,h), Object(id,parent),im_idle(nullptr), 
				  im_hover(nullptr),im_selected(nullptr) 
{
    Environment *env = Environment::get_instance();
	type = IDLE;

    shared_ptr<Resource> r;

	if ( idle_image != "" )
	{
		r = env->resources_manager->get(Resource::IMAGE, idle_image);
    	im_idle = dynamic_cast<Image *>(r.get());
	}
	if(on_hover_image != "")
	{	
   		r = env->resources_manager->get(Resource::IMAGE, on_hover_image);
	    im_hover = dynamic_cast<Image *>(r.get());
	}
	if(selected_image != "")
	{
   		r = env->resources_manager->get(Resource::IMAGE, selected_image);
	    im_selected = dynamic_cast<Image *>(r.get());
	}

    env->events_manager->register_mouse_button_event_listener(this);
    env->events_manager->register_mouse_motion_event_listener(this);
}
 
Button::~Button()
{
    Environment *env = Environment::get_instance();
    env->events_manager->unregister_mouse_button_event_listener(this);
    env->events_manager->unregister_mouse_motion_event_listener(this);
}

void 
Button::on_hover(double x, double y)
{
	if ( (x >= this->x() && x <= this->x() + this->w()) &&
		 (y >= this->y() && y <= this->y() +this->h()) )
        type = ON_HOVER;
    else
    	type = IDLE;
}
    
void 
Button::update_self(unsigned long elapsed)
{
	
}

void 
Button::draw_self()
{
    Environment *env = Environment::get_instance();
    if (type == IDLE)
    	env->canvas->draw(im_idle, this->x(), this->y());
    else if (type == ON_HOVER)
    	env->canvas->draw(im_hover, this->x(), this->y());
	else if (type == SELECTED)
		env->canvas->draw(im_selected, this->x(), this->y());
}

bool 
Button::onMouseButtonEvent(const MouseButtonEvent& event)
{
	//cout <<"\r OnMouseButtonEvent(x = " <<event.x()<<"y = "<<event.y()<<")"<<endl;
	return false;
}

bool 
Button::onMouseMotionEvent(const MouseMotionEvent& event)
{
    on_hover(event.x(),event.y()); 
	//cout <<"\r OnMouseMotionEvent(x = " <<event.x()<<"y = "<<event.y()<<")"<<endl;
	return false;
}
    
void 
Button::selected(double x , double y)
{
}
