#ifndef STAGE_H
#define STAGE_H

#include <core/object.h>
#include <core/image.h>

#include <core/sprite.h>
#include <vector>
#include <utility> 
#include <memory>

using std::string;
using std::shared_ptr;
using std::vector;
using std::pair;

class GameControl;
class Layer;

class Stage : public Object
{
public:
    Stage(Object * parent,ObjectID id);
	void add_layer(Layer* layer);
    void draw_self();
	void update_self(unsigned long elapsed);
private:
	vector < Layer* > m_layers;
};

#endif
