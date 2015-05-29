#ifndef NPC_H
#define NPC_H

#include <core/object.h>
#include <core/animation.h>

class NPC: public Object
{
public:
	NPC(Object* parent,ObjectID id,const string& image,
	double x,double y, double w, double h);
	~NPC();
    void draw_self();
	void update_self(unsigned long elapsed);
private:
 Animation* m_animation;
};



#endif
