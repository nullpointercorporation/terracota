#include "gameover.h"
#include <util/button.h>
#include <core/object.h>



GameOver::GameOver()
	: Level("gameover")
{
	Environment* env = Environment::get_instance();
	
	double w = env->canvas->w();
	double h = env->canvas->h();
	
	m_background = env->resources_manager->get_texture("res/images/gameover/gameover.png");
}

GameOver::~GameOver()
{
}

bool 
GameOver::on_message(Object* object, MessageID id, Parameters)
{
	if (id != Button::clickedID)
        return false;

    Button* button = dynamic_cast<Button* >(object);
	if(! button)	return false;

	return true;
}
	
void 
GameOver::draw_self()
{
	Environment* env = Environment::get_instance();
	env->canvas->clear(Color::WHITE);
	env->canvas->draw(m_background.get());
}

