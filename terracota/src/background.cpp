#include "background.h"

Background::Background(
	ObjectID id,shared_ptr<Texture> texture,
	double x, double y, double w, double h)
	: Layer(id,texture,x,y,w,h)
{
}

Background::~Background()
{
}

void 
Background::move_camera(double x,double y)
{
	set_clip_position(x,y);
}

pair<double,double>
Background::center()
{
	double x = position_clip().first;
	double y = position_clip().second;
	double h = dimension_clip().first;
	double w = dimension_clip().second;
	double xc = x + w/2;
	double yc = y + h/2;
	return make_pair(xc,yc);
}
