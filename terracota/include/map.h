#ifndef MAP_H
#define MAP_H

#include <core/level.h>
#include <list>
#include <string.h>
#include "map_manager.h"
#include "stage.h"

using std::shared_ptr;
class Map: public Level
{
public:
	Map(ObjectID id,const string& conf_file);
	~Map();
    void run_physics(unsigned long elapsed);
	void next_map(const string& object);
private:
	MapManager* m_map_manager;
};

#endif
