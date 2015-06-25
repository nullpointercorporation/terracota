#include "titlescreen.h"

#include <core/environment.h>
#include <util/button.h>
#include "gameflow.h"

#include <iostream>

using namespace std;

TitleScreen::TitleScreen()
    : Level("title")
{
	GameFlow::get_instance()->set_state(GameState::MENU);

	Environment* env = Environment::get_instance();
	m_background = env->resources_manager->get_texture("res/images/titlescreen/background_terracota.jpg");

    double w  = env->canvas->w();
    double h  = env->canvas->h();
    double bx=263,by=76,space=20;
 
    Button* m_continue = new Button(this,"continue", "res/images/buttons/menu_buttom/continue_idle.png",
                                                     "res/images/buttons/menu_buttom/continue_active.png");

    Button* m_start = new Button(this,"start", "res/images/buttons/menu_buttom/start_idle.png",
                                               "res/images/buttons/menu_buttom/start_active.png");

	Button* m_options = new Button(this,"options","res/images/buttons/menu_buttom/options_idle.png",
                                                  "res/images/buttons/menu_buttom/options_active.png");

    Button* m_quit = new Button(this,"quit","res/images/buttons/menu_buttom/quit_idle.png",
                                            "res/images/buttons/menu_buttom/quit_active.png");


    m_continue->add_observer(this);
    m_start->add_observer(this);
    m_options->add_observer(this);
    m_quit->add_observer(this);
        
    add_child(m_continue);
    add_child(m_start);
    add_child(m_options);
    add_child(m_quit);

    m_continue->set_position((w-bx)/2,h/4+space*0+by*0);
    m_start->set_position((w-bx)/2,h/4+space*1+by*1);
    m_options->set_position((w-bx)/2,h/4+space*2+by*2);
    m_quit->set_position((w-bx)/2,h/4+space*3+by*3);

}

TitleScreen::~TitleScreen()
{
}

void 
TitleScreen::draw_self()
{
    Environment* env = Environment::get_instance();
    env->canvas->clear(Color::WHITE);
	env->canvas->draw(m_background.get());
}

bool
TitleScreen::on_message(Object* object, MessageID id, Parameters)
{
    if (id != Button::clickedID)
    {
        return false;
    }
    
    Button* button = dynamic_cast<Button *>(object);
    
    if (not button)
        return false;
    if(button->id() == "start")
        set_next("map2");
	if (button->id() == "options")
		set_next("options");

    finish();
    return true;
}









