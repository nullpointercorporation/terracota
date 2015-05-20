#ifndef H_INTI_H
#define H_INTI_H

#include <core/sprite.h>

using std::unique_ptr;
using std::pair;

class Inti: public Sprite
{
public:
    typedef enum { NONE, IDLE, WALKING,ATACKING, INTERACTING } State;
    typedef enum { MOVED, STOPPED,CHANGING,INTERACTED } Event;
    typedef enum { LEFT, RIGHT ,UP,DOWN } Direction;

	Inti(Object* parent,const string& id);
	~Inti();

	Direction direction() const;
	void set_direction(Direction direction);
	const pair<double,double>& moviment() const;
	void set_moviment(double xaxis,double yaxis);
private:
	class Impl;
	unique_ptr<Impl> m_impl;
};

#endif