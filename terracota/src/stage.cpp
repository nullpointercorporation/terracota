#include "stage.h"

Stage::Stage(ObjectID id)
	:Level(id)
{
	person = new Character(this,"firstPerson","res/images/characters/player_sample_1.png");
	person->set_position(0,0);
	person->set_speed(10,10);

	add_child(person);
	

}

void 
Stage::draw_self(){
	Environment* env = Environment::get_instance();
	env->canvas->clear();
}
