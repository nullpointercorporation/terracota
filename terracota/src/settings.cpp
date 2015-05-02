#include "settings.h"

#include "environment.h"
#include "button.h"

Settings::Settings()
	: Level("settings")
{
	Environment* env = Environment::get_instance();
	
	double w = env->canvas->w();
	double h = env->canvas->h();

	double bw = 100;
	double bh = 50;
	
	double bx = (w - bw)/2;
	double by = h/2;

	Button* fullscreen = new Button(this, "fullscreen",bx,by,bw,bh);
	Button* back = new Button(this,"back",bx,by+bh+20,bw,bh);

	fullscreen->add_observer(this);
	back->add_observer(this);

	add_child(fullscreen);
	add_child(back);
}
Settings::~Settings()
{

}

void
Settings::draw_self()
{
	Environment* env = Environment::get_instance();
	env->canvas->clear(Color::WHITE);
}

bool
Settings::on_message(Object* object, MessageID id, Parameters)
{
	if (id != Button::clickedID)
		return false;
	
	Button* button = dynamic_cast<Button* >(object);

	if( not button)
		return false;
	
	if( button->id() == "back")
		m_next = "title";
	if( button->id() == "fullscreen")
	{
		Environment::get_instance()->video->set_fullscreen(true);	
		m_next = "title";
	}
	m_done = true;
	return true;
}
