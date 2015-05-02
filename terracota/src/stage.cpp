#include "stage.h"
#include "animation.h"

Stage::Stage(ObjectID id)
	:Level(id)
{
	person = new Character(this,"firstPerson");
	person->set_position(0,0);
	person->set_speed(10,10);

	Animation* animation = new Animation( "res/images/characters/boss_sheet.png",0,30,360,360,7);
	person->set_animation(animation);

	add_child(person);

}

void 
Stage::draw_self(){
	Environment* env = Environment::get_instance();
	env->canvas->clear();
}
