#include "button.h"
#include "image.h"
#include "environment.h"

Button::Button(const string& id, Object * parent,double x, double y, double w, double h,const string& idle_image, const string& on_hover_image)
	: Rect(x,y,w,h), Object(id,parent),im_idle(nullptr), im_hover(nullptr) 
{
    Environment *env = Environment::get_instance();
    shared_ptr<Resource> r = env->resources_manager->get(Resource::IMAGE,
        idle_image);
    im_idle = dynamic_cast<Image *>(r.get());
    r = env->resources_manager->get(Resource::IMAGE, on_hover_image);
    im_hover = dynamic_cast<Image *>(r.get());
}
 
Button::~Button()
{
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
    else
    	env->canvas->draw(im_hover, this->x(), this->y());
}
