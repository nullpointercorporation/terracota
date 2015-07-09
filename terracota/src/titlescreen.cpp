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
	m_background = env->resources_manager->get_texture("res/images/titlescreen/background.png");

    double w  = env->canvas->w();
    double h  = env->canvas->h();
    double bx=263,by=76,space=20;
 
    Button* m_start = new Button(this,"start", "res/images/titlescreen/play.png",
                                               "res/images/titlescreen/play.png");

    Button* m_continue = new Button(this,"continue", "res/images/titlescreen/continue.png",
                                                     "res/images/titlescreen/continue.png");

	Button* m_options = new Button(this,"options","res/images/titlescreen/options.png",
                                                  "res/images/titlescreen/options.png");

    Button* m_quit = new Button(this,"quit","res/images/titlescreen/quit.png",
                                            "res/images/titlescreen/quit.png");

    m_continue->add_observer(this);
    m_start->add_observer(this);
    m_options->add_observer(this);
    m_quit->add_observer(this);
        
    add_child(m_continue);
    add_child(m_start);
    add_child(m_options);
    add_child(m_quit);

    double dx = -65;
    double dy = -80;

    m_start->set_position(189 + dx, 492 + dy);
    m_continue->set_position(425 + dx, 498 + dy);
    m_options->set_position(661 + dx, 492 + dy);
    m_quit->set_position(898 + dx, 504 + dy);
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
        set_next("map1");
	if (button->id() == "options")
		set_next("options");

    finish();
    return true;
}









