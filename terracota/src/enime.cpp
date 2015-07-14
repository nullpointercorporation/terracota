#include "enime.h"
#include "life.h"
#include <core/animation.h>
#include "gamecontrol.h"
#include <cmath>

Enime::Enime(Object* parent,ObjectID id,int time,int radius,int speed,int force)
	: Object(parent,id),m_life(new Life(1,0)),m_animation(nullptr),m_start(0),m_time(time),m_radius(radius),m_speed(speed),m_allow_attack(true),m_rows(0),m_die_animation(nullptr),m_key(false),m_force(force)
{
}


void 
Enime::set_has_key(bool key)
{
    m_key = key;
}


bool 
Enime::has_key()
{
    return m_key;
}


Enime::~Enime()
{
	delete m_animation;
}

#include <iostream>
using namespace std;
void
Enime::set_animation(const string& file,double x,double y,
			   double w,double h, double n_frame, 
			   double frame_rate,bool animate,int rows)
{
	m_animation = new Animation(file,x,y,w,h,n_frame,frame_rate,animate);
	set_dimensions(w,h);
	m_rows = rows;
}


void
Enime::set_die_animation(const string& file,double x,double y,
			   double w,double h, double n_frame, 
			   double frame_rate,bool animate,int rows)
{
	m_die_animation = new Animation(file,x,y,w,h,n_frame,frame_rate,animate);
	m_rows_die = rows;
}

bool
Enime::can_attack()
{
   return	m_allow_attack;
}

void 
Enime::set_can_attack(bool can)
{
	m_allow_attack = can;
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
			if (m_rows > 0 )
				m_animation->set_row(1);
		}
		else
		{
			set_x(x()-m_speed);
			if (m_rows > 0)
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


#include <core/rect.h>
#include "gamecontrol.h"
#include "inti.h"
void
Enime::update_self(unsigned long elapsed)
{
	if ( m_start == 0) m_start = elapsed;

	if (m_life->life() <= 0   && elapsed-m_start > m_time  )
	{
		die();
		m_start = 0;
	}

	if (elapsed-m_start > m_time  && m_allow_attack)
	{
		follow_main_char();
		m_start=0;
	}


    if (  m_rows_die == 0 )
        m_die_animation->reset();
    if ( m_rows == 0)
        m_animation->reset();

    m_die_animation->update(elapsed);
        


	m_animation->update(elapsed);
			
	//Rect r =GameControl::get_instance()->get_inti()->bounding_box();
 	//cout << "init:"<<r.x() << "x"<<r.y()<<"x"<<r.w()<<"x"<<r.h() <<endl;
}

void
Enime::die()
{
	set_walkable(true);
	set_visible(false);
	set_position(0,0);
	set_dimensions(0,0);
}


void
Enime::draw_self()
{
	if ( m_life->life() <= 0  )
		m_die_animation->draw(x(),y());
	else
		m_animation->draw(x(),y());
}

int 
Enime::force()
{
    return m_force;
}

void 
Enime::damage(int life)
{
	m_life->damage(life);
}

