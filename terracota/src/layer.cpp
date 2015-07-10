#include "layer.h"
#include <core/environment.h>
 
#include <iostream>
using namespace std;
Layer::Layer(Object* parent,ObjectID id,
	  shared_ptr<Texture> texture,
	  double x, double y, double w, double h,double pos_x,
	  double pos_y)
	: Object(parent,id),m_texture(texture),m_clip(Rect(x,y,w,h)),m_hide(false) 
{
	set_dimensions(w,h);
	set_position(pos_x,pos_y);
}

Layer::~Layer()
{
}

double
Layer::ymin()
{
	return y()+h();
}
double
Layer::xmin()
{
	return x()-w();	
}

void
Layer::draw_self()
{
	Environment* env = Environment::get_instance();
	if (not m_clip.w() and not m_clip.h() )
    	env->canvas->draw(m_texture.get(),x(),y());
	else
    	env->canvas->draw(m_texture.get(),m_clip,x(),y());
}

pair<double,double>
Layer::position_clip()
{
	return make_pair(m_clip.x(),m_clip.y());
}

pair<double,double> 
Layer::dimension_clip()
{
	return make_pair(m_clip.w(),m_clip.h());
}

void 
Layer::set_clip_position(double x,double y )
{
	m_clip.set_position(x,y);
}

void 
Layer::set_clip_dimension(double w,double h)
{
	m_clip.set_dimensions(w,h);
}

void
Layer::set_can_hide(bool can_hide)
{
	can_hide = can_hide;
}

bool 
Layer::can_hide()
{
	return m_hide;
}
