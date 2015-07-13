#ifndef H_INTI_H
#define H_INTI_H

#include <core/sprite.h>

using std::unique_ptr;
using std::pair;

class Life;
class Inti: public Sprite
{
public:
    typedef enum { NONE, IDLE, WALKING,ATTACKING, INTERACTING } State;
    typedef enum { MOVED, STOPPED,ATTACKED,CHANGING,INTERACTED } Event;
    typedef enum { LEFT, RIGHT ,UP,DOWN } Direction;

	Inti(Object* parent,const string& id);
	~Inti();


	void set_key(bool key);
	bool key();
	Direction direction() const;
	void set_direction(Direction direction);
	const pair<double,double>& moviment() const;
	void set_moviment(double xaxis,double yaxis);
	Life* life();
    bool can_change();
    bool on_message(Object *sender, MessageID id, Parameters p);

private:
	class Impl;
	unique_ptr<Impl> m_impl;
};

#endif
