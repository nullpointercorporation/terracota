#include "stage.h"
#include <core/animation.h>
#include <core/environment.h>

#include "gameflow.h"
#include "gamecontrol.h"
#include "inti.h"
#include "background.h"
#include <core/animation.h>
#include "npc.h"

#include <iostream>


using namespace std;

Stage::Stage(Object* parent,ObjectID id)
	:Object(parent,id),gamecontrol(nullptr)
{
	Environment* env  = Environment::get_instance();
	GameFlow::get_instance()->set_state(GameState::PLAYING);
    gamecontrol = new GameControl(this,"gamecontrol");

	add_child(gamecontrol);

}

void 
Stage::update_self(unsigned long elapsed)
{
	Environment* env = Environment::get_instance();
	Background* b = (( Background*) m_layers[0]);

	Inti* inti = gamecontrol->get_main_char();
	pair<double,double> coords = inti->moviment();	
    b->move_camera(coords);

    for (unsigned int i=1;i<m_layers.size();i++)
        m_layers[i]->reposition(b->camera_moviment());

    if (!b->vertical(env->canvas->h())){
        inti->set_y(env->canvas->h()/2);
    }
    if (!b->horizontal(env->canvas->w())){
        inti->set_x(env->canvas->w()/2);
    }
}

void 
Stage::draw_self(){
	pair<double,double> coords = m_layers[0]->position_clip();	
	Environment* env = Environment::get_instance();
	env->canvas->clear();
    
    m_layers[0]->draw();

    for( unsigned int i=1;i<m_layers.size();i++)
    {
        m_layers[i]->draw();
    }

}

void 
Stage::add_layer(Layer* layer)
{
    m_layers.push_back(layer);
}
