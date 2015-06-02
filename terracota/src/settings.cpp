#include "settings.h"

#include <core/environment.h>
#include "button.h"
#include "gameflow.h"

Settings::Settings()
	: Level("settings")
{
	GameFlow::get_instance()->set_state(GameState::SETTINGS);

	Environment* env = Environment::get_instance();
	
	double w = env->canvas->w();
	double h = env->canvas->h();

	double bw = 304;
	double bh = 93;
	
	double bx = (w-bw)/2;
	double by = 90; 

	m_background = env->resources_manager->get_texture("res/images/titlescreen/background_terracota.jpg");

    Button* fullscreen = new Button(this, "fullscreen","res/images/buttons/fullscreen_mode_button.png",bx,by+100,bw,bh);
    Button* window_mode = new Button(this, "window_mode","res/images/buttons/window_mode_button.png",bx,by+200,bw,bh);
	Button* back = new Button(this,"back","res/images/buttons/back_button.png",bx,by+bh+300,bw,bh);

	back->add_observer(this);
    window_mode->add_observer(this);
    fullscreen->add_observer(this);
        
    add_child(window_mode);
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
		set_next("title");
	    finish();
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
