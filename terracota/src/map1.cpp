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
			new Background("background",handle);

	m_stage->add_layer(background);
}

shared_ptr<Texture> 
Map1::get_texture(const string& text)
{
	Environment* env = Environment::get_instance();
	return env->resources_manager->get_texture(text);
}


