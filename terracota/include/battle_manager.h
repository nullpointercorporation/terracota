#ifndef BATTLE_MANAGER_H
#define BATTLE_MANAGER_H


#include <core/object.h>
#include <core/settings.h>
#include <core/environment.h>
#include <list>
#include "map.h"

class BattleManager
{
public:
	static BattleManager* get_instance();
	void set_map(Map* mapa);
	void fight(Object* object, ObjectID enime);
	void remove_children();
private:
	BattleManager();
	~BattleManager();
	Map* m_target;
	list<Object*>m_children;
};

#endif 
