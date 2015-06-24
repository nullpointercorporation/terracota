#include "bat.h"


Bat::Bat(Object* parent,ObjectID id)
	: Object(parent,id), m_animation(new Animation("res/images/enemies/bat.png",0,0,79,86,1,false))
{

}

Bat::~Bat(){}

void 
Bat::draw_self()
{
	m_animation->draw(x(),y());
}
void 
Bat::update_self(unsigned long elapsed)
{
}
