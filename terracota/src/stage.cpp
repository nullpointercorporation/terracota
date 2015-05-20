#include "stage.h"
#include <core/animation.h>
#include <map>
#include "gameflow.h"

Stage::Stage(ObjectID id,const string& background, double x, double y, double w,double h )
	:Level(id),m_background(nullptr),m_rect(Rect(x,y,w,h))
{
	GameFlow::get_instance()->set_state(GameState::PLAYING);

	Environment* env = Environment::get_instance();
	m_background = env->resources_manager->get_texture(background);

/*    map<int,Animation* > actions_m;
    actions_m[Sprite::IDLE] = new Animation("res/images/characters/idle_char.png", 0, 0, 128, 172, 10,100, true);
    actions_m[Sprite::RUNNING] = new Animation("res/images/characters/running_char.png", 0, 0, 128,  172, 10, 50, true);
	Sprite* ninja_m = new Sprite(this,"ninja_m",actions_m);
	ninja_m->set_position(10,150);

    map<int,Animation* > actions_f;
    actions_f[Sprite::IDLE] = new Animation("res/images/characters/idle_f_char.png", 0, 0, 128, 172, 10,100, true);
    actions_f[Sprite::RUNNING] = new Animation("res/images/characters/running_ninja_f_char.png", 0, 0, 128,  172, 10, 50, true);
	Sprite* ninja_f = new Sprite(this,"ninja_f",actions_f);
	ninja_f->set_position(10,350);

	GameControl* c = GameControl::get_instance();
	c->set_main_char(ninja_m);
	c->set_secundary_char(ninja_f);

	add_child(ninja_m);	
	add_child(ninja_f);
*/
}


void 
Stage::draw_self(){
	Environment* env = Environment::get_instance();
	env->canvas->clear();
    env->canvas->draw(m_background.get(),m_rect);
}

