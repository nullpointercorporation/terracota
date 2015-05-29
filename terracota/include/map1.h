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
	void generate_npc();
	shared_ptr<Texture> get_texture(const string& text);
private:
	Stage* m_stage;
};

#endif
