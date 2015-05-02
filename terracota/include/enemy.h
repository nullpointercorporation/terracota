#ifndef H_ENEMY_H
#define H_ENEMY_H

#include "object.h"

class Animation;

class Enemy : public Object
{
public:
	Enemy( Object* parent = nullptr,ObjectID id = "");
	virtual ~Enemy();

	void set_animation(Animation* animation);	
	void draw_self();
	void update_self(unsigned long elapsed);
private:
	Animation* m_animation;
};

#endif
