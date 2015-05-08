#include "stage.h"
#include "animation.h"
#include "character.h"

Stage::Stage(ObjectID id,const string& background, double x, double y, double w,double h )
	:Level(id),m_background(nullptr),m_rect(Rect(x,y,w,h))
{
	Environment* env = Environment::get_instance();
	m_background = env->resources_manager->get_image(background);

	Animation* idle  = new Animation("res/images/characters/idle_char.png",0,0,111.8,312,10,100,true);
	Animation* running  = new Animation("res/images/characters/running_char.png",0,0,162,361,10,50,true);
	Character* p = new Character(this,"person",idle,running);

	p->set_position(10,150);

	add_child(p);	
}

void 
Stage::draw_self(){
	Environment* env = Environment::get_instance();
	env->canvas->clear();
    env->canvas->draw(m_background.get(),m_rect);
}

