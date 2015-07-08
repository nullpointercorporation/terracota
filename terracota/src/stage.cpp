#include "stage.h"
#include <core/animation.h>
#include <core/environment.h>

#include "layer.h"
#include "gameflow.h"
#include "gamecontrol.h"
#include "inti.h"
#include "background.h"

#include <iostream>
using namespace std;
Stage::Stage(Object* parent,ObjectID id)
	:Object(parent,id)
{
}

void 
Stage::update_self(unsigned long elapsed)
{
}

void 
Stage::draw_self(){
}

void 
Stage::add_layer(Layer* layer)
{
}
