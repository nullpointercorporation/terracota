#include "character.h"
#include  "image.h"
#include "environment.h"

using std::string;

Character::Character(Object *parent,ObjectID id,const string& sprites,int w, int h)
	: Object(parent,id), m_sprites(nullptr),m_clip(Rect(10,10,w,h)),
	  m_speed_x(0),m_speed_y(0)
{
    Environment* env = Environment::get_instance();
    shared_ptr<Resource> r;
    r  = env->resources_manager->get(Resource::IMAGE, sprites);
	
	m_sprites = dynamic_cast<Image *>(r.get());
	
    env->events_manager->register_keyboard_event_listener(this);
    env->events_manager->register_joystick_event_listener(this);
}

Character::~Character()
{
    Environment* env = Environment::get_instance();
    env->events_manager->unregister_keyboard_event_listener(this);
    env->events_manager->unregister_joystick_event_listener(this);
}

void 
Character::draw_self()
{
	Environment* env = Environment::get_instance();	
	env->canvas->draw(m_sprites,m_clip,x(),y());
}

void 
Character::update_self(unsigned long elapsed)
{
	if ( not m_speed_x && not m_speed_y)
	{
		m_last = 0;
		return;		
	}

	if ( not m_last )
		m_last = elapsed;
	Environment* env = Environment::get_instance();

	double px = x() + m_speed_x *((elapsed - m_last)/1000.0);
	double py = y() + m_speed_y *((elapsed - m_last)/1000.0);
	m_last = elapsed;
	
	if (px < 0)	px = 0;
	if (py < 0)	py = 0;
	if (px + w() >= env->canvas->w()) px = env->canvas->w() - w();
	if (py + h() >= env->canvas->h()) py = env->canvas->h() - h();	
	set_position(px,py);
}
	
void 
Character::set_speed(double x, double y)
{
	speed[0] = x;
	speed[1] = y;
}

double 
Character::speed_x()
{
	return speed[0];
}

double 
Character::speed_y()
{
	return speed[1];
}
