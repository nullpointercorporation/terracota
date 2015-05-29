#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "layer.h"
#include <core/rect.h>

class Background: public Layer
{
public:
	Background(ObjectID id,
			   shared_ptr<Texture> texture,
			   double x=0, double y=0, double w=0, double h=0);
	~Background();
	void move_camera(pair<double,double> coords);
	void set_camera(double x, double y);
	pair<double,double> center();
	bool vertical(double d);
	bool horizontal(double d);
	pair<double,double> camera_moviment();
private:
	double m_x,m_y;
};

#endif
