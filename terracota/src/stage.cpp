#include "stage.h"
#include "animation.h"
#include <map>
#include "sprite.h"
#include "gameflow.h"

Stage::Stage(ObjectID id,const string& background, double x, double y, double w,double h )
	:Level(id),m_background(nullptr),m_rect(Rect(x,y,w,h))
{
	GameFlow::get_instance()->set_state(GameState::PLAYING);

	Environment* env = Environment::get_instance();
	m_background = env->resources_manager->get_image(background);


    map<int,Animation* > actions;
    actions[Sprite::IDLE] = new Animation("res/images/characters/idle_char.png", 0, 0, 128, 172, 10,100, true);
    actions[Sprite::RUNNING] = new Animation("res/images/characters/running_char.png", 0, 0, 128,  172, 10, 50, true);

	Sprite* person = new Sprite(this,"person",actions);

	person->set_position(10,250);

	add_child(person);	
}

void 
Stage::draw_self(){
	Environment* env = Environment::get_instance();
	env->canvas->clear();
    env->canvas->draw(m_background.get(),m_rect);
}

