#include "map1.h"
#include "layer.h"
#include "background.h"


Map1::Map1(ObjectID id)
	: Level(id), m_stage(nullptr)
{
	m_stage = new Stage(this,"map1"); 
	add_child(m_stage);
	generate_map();
}

Map1::~Map1()
{
}

void 
Map1::generate_map()
{
	Environment* env = Environment::get_instance();
	shared_ptr<Texture> handle;
	handle = get_texture("res/images/stages/first_map/1.jpg");
	Background* background = 
			new Background("background",handle,
				0,0,env->canvas->w(),env->canvas->h());
	background->set_camera(0,0);
	m_stage->add_layer(background);
	generate_npc();
}

void
Map1::generate_npc()
{
	Environment* env = Environment::get_instance();
    Layer* l = new Layer("sogra",env->resources_manager->get_texture("res/images/characters/npcs/sogra.png"),0,0,79,172);
	l->set_position(1000,800);
    m_stage->add_layer(l);   


    l = new Layer("sogra",env->resources_manager->get_texture("res/images/characters/npcs/ferreiro.png"),0,0,117,217);
	l->set_position(800,600);
    m_stage->add_layer(l);   


    l = new Layer("sogra",env->resources_manager->get_texture("res/images/characters/npcs/pai-killa.png"),0,0,125,232);
	l->set_position(1000,500);
    m_stage->add_layer(l);   

}

shared_ptr<Texture> 
Map1::get_texture(const string& text)
{
	Environment* env = Environment::get_instance();
	return env->resources_manager->get_texture(text);
}


