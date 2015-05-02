#include "enemy.h"
#include "animation.h"

Enemy::Enemy( Object* parent,ObjectID id)
	: Object(parent,id)	
{
}

Enemy::~Enemy()
{
}

void 
Enemy::set_animation(Animation* animation)
{
	m_animation = animation;
	set_dimensions(animation->w(),animation->h());
}

void 
Enemy::draw_self()
{
	m_animation->draw(x(),y());
}

void
Enemy::update_self(unsigned long elapsed )
{
	m_animation->update(elapsed);
}
