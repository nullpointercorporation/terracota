#include "map_manager.h"
#include <core/image.h>
#include <iostream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include "map.h"
#include "layer.h"
#include "gameflow.h"
#include "gamecontrol.h"
#include "npc.h"
#include "inti.h"
#include "dialogue.h"
#include "enime.h"
#include "life.h"

using namespace std;

static MapManager* instance = nullptr;

MapManager* 
MapManager::get_instance()
{
	if (not instance)
		instance = new MapManager();
	return instance;
}


MapManager::MapManager()
	: m_settings(nullptr), env(nullptr)
{
	GameFlow::get_instance()->set_state(GameState::PLAYING);
}

void
MapManager::set_map(Map* map,const string& file)
{
	m_target = (Object*)map; 
    env = Environment::get_instance();	
	m_settings = env->resources_manager->get_settings(file);
	remove_children();
}

void
MapManager::add_colisions()
{
    list<string> objects;
	string text = m_settings->read<string>("list","colisions","null");
    if (text != "null"){
        objects = make_list(text);
    	for( auto obj: objects)
	    	add_object(obj);
    }
}

void
MapManager::next_map(const string& object)
{
	string next_level = m_settings->read<string>(object,"next_level","null");
	string next_pos = m_settings->read<string>(object,"pos","0x0");
    double x,y;
    sscanf(next_pos.c_str(),"%lfx%lf",&x,&y);

    GameControl* gamecontrol = GameControl::get_instance(); 
    Inti* inti = gamecontrol->get_inti();
    inti->set_position(x,y);

    Map* mapa = (Map*)m_target; 
    mapa->set_next(next_level);
    mapa->finish();
}

void
MapManager::remove_children()
{
	Map* mapa= (Map*) m_target;
	list<Object*> m_children = mapa->children();
	for (auto obj : m_children)	
	{
		m_target->remove_child(obj);
	}
}

void 
MapManager::add_objects()
{
    list<string> objects;
	string text = m_settings->read<string>("list","objects","null");
    if (text != "null"){
        objects = make_list(text);
    	for( auto obj: objects)
	    	add_object(obj);
        add_gamecontrol();
    }
}

list<string> 
MapManager::make_list(const string& text)
{
    list<string> objects;
    string name;
    for (unsigned int i=0;i<text.size();i++)
    {
        if ( ',' != text[i]){
            name += text[i];
        }
        else
        {
            objects.push_back(name);
            name = "";
        }
    }
    if (text.size() > 1)
        objects.push_back(name);
    return objects;
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
	    file = m_settings->read<string>(element,"file","null");
	    handle = get_texture(file);
		Layer * layer = new Layer(m_target, element, handle, 
					box_x, box_y, box_w, box_h, pos_x, pos_y);
		layer->set_walkable(walkable);
		layer->set_visible(visible);
		m_target->add_child(layer);
	}
	else if (type == "Object")
	{
		Object* obj = new Object(m_target,element,box_x,box_y,box_w,box_h);
		obj->set_position(pos_x,pos_y);
		obj->set_walkable(walkable);
        obj->set_visible(visible);
		m_target->add_child(obj);
	}
    else if (type == "NPC")
    {
	    file = m_settings->read<string>(element,"file","null");
        NPC* npc = new NPC(m_target,element,file);
        npc->set_dimensions(box_w,box_h);
		npc->set_position(pos_x,pos_y);
		npc->set_walkable(walkable);
		npc->set_visible(visible);
        m_target->add_child(npc);
    }
	else if (type == "Enime")
	{
		int time,speed,radius;
		double x,y,w,h;
		double animation_frames,animation_fps;
		bool loop;

	    time = m_settings->read<int>(element,"time",0);
	    speed = m_settings->read<int>(element,"speed",0);
	    radius = m_settings->read<int>(element,"radius",0);
		Enime* enime = new Enime(m_target,element,time,radius,speed);

		// animation normal
	    file = m_settings->read<string>(element,"file","null");
		string box = m_settings->read<string>(element,"box","0.0x0.0x0.0x0.0");
		sscanf(box.c_str(),"%lfx%lfx%lfx%lf",&x,&y,&w,&h);
		animation_frames = m_settings->read<int>(element,"animation_frames",0);
		animation_fps = m_settings->read<int>(element,"animation_fps",0);
		loop = m_settings->read<bool>(element,"loop",true);

		int  rows = m_settings->read<int>(element,"rows",0);
		int  life = m_settings->read<int>(element,"life",0);
		enime->set_animation(file,x,y,w,h,animation_frames,animation_fps,loop,rows);
		enime->get_life()->set_life(life);
		// animation die
	    file = m_settings->read<string>(element,"file_die","null");
		box = m_settings->read<string>(element,"box_die","0.0x0.0x0.0x0.0");
		sscanf(box.c_str(),"%lfx%lfx%lfx%lf",&x,&y,&w,&h);
		animation_frames = m_settings->read<int>(element,"animation_frames_die",0);
		animation_fps = m_settings->read<int>(element,"animation_fps_die",0);
		loop = m_settings->read<bool>(element,"loop_die",true);
		rows = m_settings->read<int>(element,"rows_die",0);
		enime->set_die_animation(file,x,y,w,h,animation_frames,animation_fps,false,0);
		// set position enime 
		string pos = m_settings->read<string>(element,"pos","0.0x0.0");
		sscanf(pos.c_str(),"%lfx%lf",&x,&y);

		enime->set_position(x,y);
		enime->set_walkable(walkable);
		enime->set_visible(visible);


		// key
		bool key = m_settings->read<bool>(element,"has_key",false);
		enime->set_has_key(key);

		m_target->add_child(enime);
	}
}

shared_ptr<Texture> 
MapManager::get_texture(const string& text)
{
	Environment* env = Environment::get_instance();
	return env->resources_manager->get_texture(text);
}

void 
MapManager::add_gamecontrol()
{
    GameControl* gamecontrol = GameControl::get_instance(); 

	// set camera
	string type = m_settings->read<string>("camera","type","null");
	double pos_x,pos_y; 
	pos_x = m_settings->read<double>("camera","pos_x",0);
    pos_y = m_settings->read<double>("limits","pos_y",0);

	if (type == "following")
	{
    	env->camera->set_mode(Camera::FOLLOWING);
    	Object* inti = gamecontrol->get_inti();
    	env->camera->follow(inti);
	}

	if (type == "static")
	{
		env->camera->set_mode(Camera::STATIC);
		env->camera->set_position(pos_x,pos_y);
	}

	// limits box
    string limits = m_settings->read<string>("limits","has_limit","null");

	if ( limits != "null")
	{
		double box_x,box_y,box_w,box_h;	
		box_x = m_settings->read<double>("limits","box_x",0);
		box_y = m_settings->read<double>("limits","box_y",0);
		box_w = m_settings->read<double>("limits","box_w",0);
		box_h = m_settings->read<double>("limits","box_h",0);
     	env->camera->set_limits(Rect(box_x, box_y, box_w, box_h));
	}
	m_target->add_child(gamecontrol);
}
