#include "menu.h"

#include "image.h"
#include "environment.h"
#include "button.h"


Menu::Menu(const string& next, const string& background)
	: Level("",next), m_background(nullptr)
{
    Environment *env = Environment::get_instance();
    shared_ptr<Resource> r = env->resources_manager->get(Resource::IMAGE,
        background);
    m_background = dynamic_cast<Image *>(r.get());
    this->create_buttons();
}

Menu::~Menu()
{
}

void 
Menu::draw_self()
{
    Environment *env = Environment::get_instance();
    env->canvas->clear();
    env->canvas->draw(m_background, 0, 0);
}

void 
Menu::create_buttons()
{
	Button* start = new Button ("start",(Object*)this,
								  250,100,304,93, "res/images/start_button.png",
                                  "res/images/start_on_hover_button.png");
	
    Button* options = new Button( "options",(Object*) this,
								  250,200,304,93,"res/images/options_button.png",
								  "res/images/options_on_hover_button.png");

    Button* quit = new Button( "quit",(Object *) this,
								  250,300,304,93,"res/images/quit_button.png",
								  "res/images/quit_on_hover_button.png");

	add_children((Object*)start);
	add_children((Object*)options);
    add_children((Object*)quit);
}

