#ifndef MAP1_H
#define MAP1_H

#include <core/level.h>
#include "stage.h"

using std::shared_ptr;
class Map1: public Level
{
public:
	Map1(ObjectID id);
	~Map1();
	void generate_map();
    void run_physics(unsigned long elapsed);
};

#endif
