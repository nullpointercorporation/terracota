#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "layer.h"
#include <core/rect.h>

using std::pair;
using std::make_pair;

class Background: public Layer
{
public:
	Background(ObjectID id,
			   shared_ptr<Texture> texture,
			   double x=0, double y=0, double w=0, double h=0);
	~Background();
	void move_camera(double x,double y);
	pair<double,double> center();
};

#endif
