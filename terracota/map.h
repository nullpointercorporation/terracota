#ifndef MAP_H
#define MAP_H

#include <object.h>
#include <vector>

class Map:public Object
{
	Map();
	~Map()
	void set_main_char(double x,double y);
	void set_secundary_char(double x,double y);

private:
	vector< shared_ptr<Texture> > layers;
};

#endif 
