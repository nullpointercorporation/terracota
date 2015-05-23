#include "titlescreen.h"

#include <core/environment.h>
#include "button.h"
#include "gameflow.h"

#include <iostream>

using namespace std;

TitleScreen::TitleScreen()
    : Level("title")
{
	GameFlow::get_instance()->set_state(GameState::MENU);
	
    Environment* env = Environment::get_instance();
    
    double w  = env->canvas->w();
    double h  = env->canvas->h();

    double bw = 304;
    double bh = 93;

    double bx = (w - bw)/2;
    double by = h/3;

	m_background = env->resources_manager->get_texture("res/images/titlescreen/background_terracota.jpg");
    Button* ok = new Button(this,"ok", "res/images/buttons/start_button.png", bx, by, bw , bh);
	Button* settings = new Button(this,"settings","res/images/buttons/option_button.png",bx,by+bh+10,bw,bh);
    Button* exit = new Button(this,"exit","res/images/buttons/quit_button.png", bx, by+bh+115, bw, bh);
    
    ok->add_observer(this);
    settings->add_observer(this);
    exit->add_observer(this);
        
    add_child(settings);
    add_child(ok);
    add_child(exit);

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
    if(button->id() == "ok")
        m_next = "map1";
	if (button->id() == "settings")
		m_next = "settings";

    m_done = true;
    return true;
}









