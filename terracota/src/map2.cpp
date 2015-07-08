#include "map2.h"
#include "layer.h"
#include "background.h"
#include "gamecontrol.h"
#include "ui.h"
#include "bat.h"
#include <list>
#include "gameflow.h"
#include "gamecontrol.h"
#include "inti.h"
#include "background.h"
#include "map_manager.h"

#include <core/object.h>

Map2::Map2(ObjectID id)
	: Level(id)
{
	GameFlow::get_instance()->set_state(GameState::PLAYING);
	generate_map();
}

Map2::~Map2()
{
}

void 
Map2::generate_map()
{
	Environment* env = Environment::get_instance();
    list<string> objects ={
            "background", "water", "home",  "door",
            "lamber1", "lamber2", "grass1", "grass2",
            "grass3",  "grass4","tree",   "branch", "rock","home2"};

    MapManager* map_manager = new MapManager(this,"res/conf/map2.conf");
    map_manager->add_objects(objects);


    Object *wall = new Object(this, "top_wall", 0, 0, 3011, 610);
    wall->set_walkable(false);
    wall->set_visible(false);
    add_child(wall);



    GameControl* gamecontrol = GameControl::get_instance(); 
    env->camera->set_mode(Camera::FOLLOWING);
    Inti* inti = gamecontrol->get_inti();
	add_child(gamecontrol);
    env->camera->follow(inti);
	env->camera->set_limits(Rect(0, 0, 3011, 1440));
}

void
Map2::run_physics(unsigned long elapsed)
{
    GameControl* gamecontrol = GameControl::get_instance(); 
    collision_one_to_all(gamecontrol->get_main_char(), children());    
}
