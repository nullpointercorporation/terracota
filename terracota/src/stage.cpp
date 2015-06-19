#include "stage.h"
#include <core/animation.h>
#include <core/environment.h>

#include "layer.h"
#include "gameflow.h"
#include "gamecontrol.h"
#include "inti.h"
#include "background.h"

#include <iostream>
using namespace std;
Stage::Stage(Object* parent,ObjectID id)
	:Object(parent,id),gamecontrol(nullptr)
{
	GameFlow::get_instance()->set_state(GameState::PLAYING);
    gamecontrol = new GameControl(this,"gamecontrol");
	add_child(gamecontrol);
}

void 
Stage::update_self(unsigned long elapsed)
{
    Environment* env = Environment::get_instance();
    env->camera->set_mode(Camera::FOLLOWING);
    Inti* main = gamecontrol->get_main_char();
    env->camera->follow(main);
}

void 
Stage::draw_self(){
	Environment* env = Environment::get_instance();
	env->canvas->clear();
    for( unsigned int i=0;i<m_layers.size();i++)
    {
        m_layers[i]->draw();
    }
}

void 
Stage::add_layer(Layer* layer)
{
    m_layers.push_back(layer);
}
