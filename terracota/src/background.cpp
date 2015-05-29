#include "background.h"

#include <iostream>
using namespace std;
using std::pair;
using std::make_pair;

Background::Background(
	ObjectID id,shared_ptr<Texture> texture,
	double x, double y, double w, double h)
	: Layer(id,texture,x,y,w,h),m_x(0),m_y(0)
{
}

Background::~Background()
{
}

void 
Background::move_camera(pair<double,double> coords )
{
	double incx,incy;
	if (coords.first > 0) {
				incx = 0.5;
				incy = 0;
				m_x =1;
	}
	else if (coords.first <0)
	{
		incx = -0.5;
		incy =0;
		m_x = -1;
	}else
	{
		m_x = 0;
	}
	if (coords.second>0){
		incx = 0;
		incy = 0.5;
		m_y = 1;
	} else if (coords.second<0) 
	{
		incx = 0;
		incy = -0.5;
		m_y = -1;
	}else{
		m_y = 0;
	}
	
	if ( m_clip.x()+incx < 0 or m_clip.x()+incx+m_clip.w()>= m_texture->w()  )
		incx = 0;
	if ( m_clip.y()+incy < 0 or m_clip.y()+incy+m_clip.h() >= m_texture->h() )
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

bool
Background::vertical(double d)
{
	if((m_texture->h() - m_clip.y() < d+20) or
	   (m_texture->h() - m_clip.y() > m_texture->h()-20))
		return true;
	return false;
}

bool
Background::horizontal(double d)
{
	if((m_texture->w() - m_clip.x() < d+20) or
	   (m_texture->w() - m_clip.x() > m_texture->w()-20))
		return true;
	return false;
}

pair<double,double>
Background::camera_moviment()
{
	return make_pair(m_x,m_y);
}
