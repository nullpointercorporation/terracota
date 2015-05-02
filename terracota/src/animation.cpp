#include "animation.h"
#include "image.h"
#include "environment.h"

Animation::Animation(const string& sprites,
		   double x , double y, double w,double h,
          int frames)
	:
	m_x(x),m_y(y),m_h(h),m_w(w),m_sprites(nullptr),m_frames(frames),current_frame(0),
	m_clip(Rect(x,y,w,h))
{
    Environment* env = Environment::get_instance();
    shared_ptr<Resource> r;
    r  = env->resources_manager->get(Resource::IMAGE, sprites);
    m_sprites = dynamic_cast<Image *>(r.get());
}


Animation::~Animation()
{
	delete m_sprites;
}

double
Animation::x()
{
	return m_x;
}

double
Animation::y()
{
	return m_y;
}

double 
Animation::h()
{
	return m_h;
}

double 
Animation::w()
{
	return m_w;
}

void 
Animation::changeAnimation(int number)
{
	double y = m_clip.h()*number;
	m_clip.set_y( y);
}

void
Animation::update()
{

	if(  current_frame+1 == m_frames  )
	{
		current_frame = 0;
		m_clip.set(m_x,  m_clip.y() );
		m_clip.set_dimensions(m_w,m_h);
		return ;
	}
	
	double x = m_clip.x() + m_w;
	m_clip.set_x(x);

	current_frame++;

}

void
Animation::draw(double position_x ,double  position_y   )
{
	Environment* env = Environment::get_instance();
	update();
	env->canvas->draw(m_sprites,m_clip,position_x,position_y);
}
