#include "settings.h"

#include "environment.h"
#include "button.h"

Settings::Settings()
	: Level("settings")
{
	Environment* env = Environment::get_instance();
	
	double w = env->canvas->w();
	double h = env->canvas->h();

	double bw = 304;
	double bh = 93;
	
	double bx = (w - bw)/2;
	double by = h/2;

	m_background = env->resources_manager->get_image("res/images/titlescreen/background_terracota.jpg");
	Button* fullscreen = new Button(this, "fullscreen","res/images/buttons/fullscreen_mode_button.png",0,0,bw,bh);
	Button* window_mode = new Button(this, "window_mode","res/images/buttons/window_mode_button.png",bx,by,bw,bh);
	Button* back = new Button(this,"back","res/images/buttons/back_button.png",bx,by+bh+20,bw,bh);

	fullscreen->add_observer(this);
	window_mode->add_observer(this);
	back->add_observer(this);

	add_child(fullscreen);
	add_child(window_mode);
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
	env->canvas->draw(m_background.get());
}

bool
Settings::on_message(Object* object, MessageID id, Parameters)
{
	if (id != Button::clickedID)
		return false;
	
	Button* button = dynamic_cast<Button* >(object);

	if( not button)
		return false;
	
	if( button->id() == "back"){
		m_next = "title";
	    m_done = true;
	}
	if( button->id() == "fullscreen")
	{
		Environment::get_instance()->video->set_fullscreen(true);	
		draw_self();
	}

	if( button->id() == "window_mode")
	{
		Environment::get_instance()->video->set_fullscreen(false);
		draw_self();
	}

	return true;
}
