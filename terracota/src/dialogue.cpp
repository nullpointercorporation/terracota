#include "dialogue.h"
#include <core/environment.h>

Dialogue::Dialogue(Object* parent,ObjectID id,const string& file)
	:Object(parent,id),m_texture(nullptr),hide(true)
{
	Environment* env = Environment::get_instance();
	m_texture = env->resources_manager->get_texture(file);
}

Dialogue::~Dialogue()
{
}

void 
Dialogue::show_quest()
{
	hide = false;
}

void 
Dialogue::draw_self()
{
	if(not hide)
	{
		Environment* env = Environment::get_instance();
		env->canvas->draw(m_texture.get(),x(),y());
	}
}

void 
Dialogue::update_self(unsigned long elapsed)
{
}
