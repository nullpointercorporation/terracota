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
	Background* b = (( Background*) m_layers[0]);
	Inti* inti = gamecontrol->get_main_char();
	pair<double,double> coords = inti->moviment();	
	
	pair<double,double>	center = b->center();

	inti->set_position(800/2,600/2);

	if (coords.first >0) b->move_camera(0.5,0);
	if (coords.first <0) b->move_camera(-0.5,0);
	if (coords.second>0) b->move_camera(0,0.5);
	if (coords.second<0) b->move_camera(0,-0.5);
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
