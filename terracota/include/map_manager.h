#ifndef MAP_MANAGER_H
#define MAP_MANAGEER_H

#include <core/object.h>
#include <core/settings.h>
#include <core/environment.h>
#include <list>

class MapManager
{
public:
    MapManager(Object* target, const string& file);
	void add_objects(list<string> objects);
	void add_object(const string& element);
	shared_ptr<Texture> get_texture(const string& text);
	void add_gamecontrol(double x,double y,double w,double h);
private:
	shared_ptr<Settings> m_settings;
	Environment* env;
	Object* m_target;
};


#endif
