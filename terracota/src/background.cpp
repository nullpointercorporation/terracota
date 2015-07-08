#include "background.h"

#include <iostream>
using namespace std;
Background::Background(
	ObjectID id,shared_ptr<Texture> texture,
	double x, double y, double w, double h,double pos_x,double pos_y)
	: Layer(nullptr,id,texture,x,y,w,h,pos_x,pos_y)
{
	set_camera(400,300);
}

Background::~Background()
{
}

void 
Background::move_camera(double x,double y)
{
	double incx=x,incy=y;
	if ( m_clip.x()+x < 0 or m_clip.x()+x+m_clip.w()>= m_texture->w()  )
		incx = 0;
	if ( m_clip.y()+y < 0 or m_clip.y()+y+m_clip.h() >= m_texture->h() )
		incy = 0;
	m_clip.set_position(m_clip.x()+incx,m_clip.y()+incy);
}

pair<double,double>
Background::center()
{
	double xc = m_clip.x() + m_clip.w()/2;
	double yc = m_clip.y() + m_clip.h()/2;
	return make_pair(xc,yc);
}

void 
Background::set_camera(double x, double y)
{
	m_clip.set_position(x,y);
}
