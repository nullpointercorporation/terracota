#include "npc.h"


#include <iostream>
using namespace std;
NPC::NPC(Object* parent,ObjectID id,const string& file)
	: Object(parent,id),m_texture(nullptr)
{
	Environment* env = Environment::get_instance();
    m_texture = env->resources_manager->get_texture(file);
}

NPC::~NPC()
{
}

void 
NPC::draw_self()
{
	Environment* env = Environment::get_instance();
	env->canvas->draw(m_texture.get(),x(),y());
}
    
void 
NPC::update_self(unsigned long elapsed)
{
}
