#ifndef ENIME_H
#define ENIME_H

#include <core/object.h>
#include <core/animation.h>

using std::unique_ptr;
using std::pair;

class Life;

class Enime: public Object
{
public:
	Enime(Object* parent,ObjectID id,int time,int radius,int speed);
	~Enime();
	void set_animation(const string& file,double x,double y,
					   double w,double h, double n_frame, 
					   double frame_rate,bool animate);
	Life* get_life();

	void damage(int life);
	void update_self(unsigned long elapsed);
	void draw_self();
    void follow_main_char();

private:
    Life* m_life;
    Animation* m_animation;
	unsigned long m_start,m_time;
	int m_radius,m_speed;
};

#endif
