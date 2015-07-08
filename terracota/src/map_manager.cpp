#include "map_manager.h"
#include <core/image.h>
#include <iostream>
#include <string.h>
#include "layer.h"
#include "gameflow.h"
#include "gamecontrol.h"
#include "inti.h"

using namespace std;

MapManager::MapManager(Object* target, const string& file)
	: m_settings(nullptr), env(nullptr),m_target(target)
{
	GameFlow::get_instance()->set_state(GameState::PLAYING);
    env = Environment::get_instance();	
	m_settings = env->resources_manager->get_settings(file);
}


void 
MapManager::add_objects(list<string> objects)
{
	for( auto obj: objects)
		add_object(obj);
}


void
MapManager::add_object(const string& element)
{
	shared_ptr<Texture> handle;
	string file,type;
	double box_x,box_y,box_w,box_h,pos_x,pos_y;
	bool walkable,visible;

	// add background
	type = m_settings->read<string>(element,"type","null");
	file = m_settings->read<string>(element,"file","null");
	handle = get_texture(file);
	box_x = m_settings->read<double>(element,"box_x",0);
	box_y = m_settings->read<double>(element,"box_y",0);
	box_w = m_settings->read<double>(element,"box_w",0);
	box_h = m_settings->read<double>(element,"box_h",0);
	pos_x = m_settings->read<double>(element,"pos_x",0);
	pos_y = m_settings->read<double>(element,"pos_y",0);
	walkable = m_settings->read<bool>(element,"walkable",true);
	visible = m_settings->read<bool>(element,"visible",true);

	if (type == "null")
	{
		cout << "Error: Type not defined in:"<< element << endl;
	}
	if (type == "Layer")
	{
		Layer * layer = new Layer(m_target, element, handle, 
					box_x, box_y, box_w, box_h, pos_x, pos_y);
		layer->set_walkable(walkable);
		layer->set_visible(visible);
		m_target->add_child(layer);
	}


}

shared_ptr<Texture> 
MapManager::get_texture(const string& text)
{
	Environment* env = Environment::get_instance();
	return env->resources_manager->get_texture(text);
}

void 
MapManager::add_gamecontrol(double x,double y,double w,double h)
{
    GameControl* gamecontrol = GameControl::get_instance(); 
    env->camera->set_mode(Camera::FOLLOWING);
    Object* inti = gamecontrol->get_inti();
	m_target->add_child(gamecontrol);
    env->camera->follow(inti);
	env->camera->set_limits(Rect(x, y, w, h));
}




