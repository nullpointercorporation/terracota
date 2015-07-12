#ifndef MAP_MANAGER_H
#define MAP_MANAGER_H

#include <core/object.h>
#include <core/settings.h>
#include <core/environment.h>
#include <list>
#include "map.h"

class Map;
class MapManager
{
public:
	static MapManager* get_instance();
	void add_objects();
	void add_colisions();
	void add_object(const string& element);
	shared_ptr<Texture> get_texture(const string& text);
	void next_map(const string& object);
	void add_gamecontrol();
	void remove_children();
	void set_map(Map* mapa,const string& file);
private:
	list<string> make_list(const string& text);
    MapManager();
	shared_ptr<Settings> m_settings;
	Environment* env;
	Object* m_target;
};


#endif
