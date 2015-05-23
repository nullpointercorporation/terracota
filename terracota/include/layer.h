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
	Layer(ObjectID id,
		  shared_ptr<Texture> texture,
		  double x=0, double y=0, double w=0, double h=0);
	~Layer();

	double ymin();
	double xmin();
	void draw();

	pair<double,double> position_clip();
	pair<double,double> dimension_clip();
	void set_clip_position(double x,double y );
	void set_clip_dimension(double w,double h);
protected:
	shared_ptr<Texture> m_texture;
	Rect m_clip;
};
#endif
