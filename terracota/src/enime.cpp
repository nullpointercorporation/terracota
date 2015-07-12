#include "enime.h"
#include "life.h"
#include <core/animation.h>
#include "gamecontrol.h"
#include <cmath>

Enime::Enime(Object* parent,ObjectID id,int time,int radius,int speed)
	: Object(parent,id),m_life(new Life(1,0)),m_animation(nullptr),m_start(0),m_time(time),m_radius(radius),m_speed(speed)
{
}

Enime::~Enime()
{
	delete m_animation;
}

void
Enime::set_animation(const string& file,double x,double y,
			   double w,double h, double n_frame, 
			   double frame_rate,bool animate)
{
	m_animation = new Animation(file,x,y,w,h,n_frame,frame_rate,animate);
}

Life*
Enime::get_life()
{
	return m_life;
}

#include <iostream>
using namespace std;


void 
Enime::follow_main_char()
{
	Object* inti = (Object*)GameControl::get_instance()->get_inti();

	double dx,dy;

	dx = inti->x() - x();
	dy = inti->y() - y();


	if ( abs(dx) <= m_radius )
	{
		if (dx>0 )
		{
			set_x(x()+m_speed);
			m_animation->set_row(1);
		}
		else
		{
			set_x(x()-m_speed);
			m_animation->set_row(0);
		}
	}
	if ( abs(dy) <= m_radius )
	{
		if (dy>0 )
			set_y(y()+m_speed);
		else
			set_y(y()-m_speed);
	}
}

void
Enime::update_self(unsigned long elapsed)
{
	if ( m_start == 0) m_start = elapsed;

	if (elapsed-m_start > m_time)
	{
		follow_main_char();
		m_start=0;
	}
	m_animation->update(elapsed);
}

void
Enime::draw_self()
{
	m_animation->draw(x(),y());
}

void 
Enime::damage(int life)
{
	m_life->damage(life);
}

