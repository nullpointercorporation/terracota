#include "map1.h"
#include "layer.h"
#include "background.h"
#include "ui.h"
#include "map_manager.h"

Map1::Map1(ObjectID id)
	: Level(id)
{
	generate_map();
}

Map1::~Map1()
{
}

void 
Map1::generate_map()
{
    list<string> objects ={"background", "water_fountain", "home",	"tree", "light", "sidewalk"};

    MapManager* map_manager = new MapManager(this,"res/conf/map1.conf");
    map_manager->add_objects(objects);
	map_manager->add_gamecontrol(0, 0, 3423, 1552);
}
void
Map1::run_physics(unsigned long elapsed)
{
    GameControl* gamecontrol = GameControl::get_instance(); 
    collision_one_to_all(gamecontrol->get_main_char(), children());    
}
