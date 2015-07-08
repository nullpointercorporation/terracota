#ifndef LAYER_H
#define LAYER_H

#include <core/object.h>
#include <core/texture.h>
#include <core/rect.h>

#include <memory>
using std::shared_ptr;
using std::pair;

class Layer : public Object
{
public:
	Layer(Object* parent,ObjectID id,
		  shared_ptr<Texture> texture,
		  double x=0, double y=0, double w=0, double h=0,
		  double pos_x =0, double pos_y = 0);
	~Layer();
	double ymin();
	double xmin();

	pair<double,double> position_clip();
	pair<double,double> dimension_clip();
	void set_clip_position(double x,double y );
	void set_clip_dimension(double w,double h);
	
	void draw_self();
protected:
	shared_ptr<Texture> m_texture;
	Rect m_clip;
};
#endif
