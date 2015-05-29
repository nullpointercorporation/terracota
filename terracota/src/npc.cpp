#include "npc.h"

NPC::NPC(Object* parent,ObjectID id,const string& image,
	double x,double y, double w, double h)
	: Object(parent,id), m_animation(nullptr)
{
	m_animation = new Animation(image,x,y,w,h,1,50,false);
}
NPC::~NPC()
{
}


void 
NPC::draw_self()
{
	m_animation->draw(x(),y());
}

void 
NPC::update_self(unsigned long elapsed)
{
	m_animation->update(elapsed);
}
