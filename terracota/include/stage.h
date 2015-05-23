#ifndef STAGE_H
#define STAGE_H

#include <core/object.h>
#include <core/image.h>

#include <core/sprite.h>
#include <vector>
#include <memory>

using std::string;
using std::shared_ptr;
using std::vector;

class GameControl;
class Layer;

class Stage : public Object
{
public:
    Stage(Object * parent,ObjectID id);
	void add_layer(Layer* layer);
private:
	GameControl* gamecontrol;
	vector < Layer* > m_layers;
    void draw_self();
};

#endif
