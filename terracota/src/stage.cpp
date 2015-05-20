#include "stage.h"
#include <core/animation.h>
#include <map>
#include "gameflow.h"
#include "gamecontrol.h"

Stage::Stage(ObjectID id,const string& background, double x, double y, double w,double h )
	:Level(id),m_background(nullptr),m_rect(Rect(x,y,w,h))
{
	GameFlow::get_instance()->set_state(GameState::PLAYING);

	Environment* env = Environment::get_instance();
	m_background = env->resources_manager->get_texture(background);

	GameControl* game  = new GameControl(this,"characters");	
	game->set_position(0,200);

	add_child(game);
}


void 
Stage::draw_self(){
	Environment* env = Environment::get_instance();
	env->canvas->clear();
    env->canvas->draw(m_background.get(),m_rect);
}

