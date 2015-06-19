#include <ui.h>
#include "inti.h"
#include "life.h"

Interface::Interface(Object * parent, ObjectID id,GameControl* gc)
	: Object(parent,id),ui_elements(nullptr) , 
	  m_killa (Rect(0,-20,490,150)), 
	  m_inti(Rect(0,150,490,150)),
	  m_button(Rect(0,320,100,100)),
	  m_life_bar(Rect(0,400,80,80)),
	  m_gc(gc)
{

    Environment* env = Environment::get_instance();	
	
	ui_elements = env->resources_manager->get_texture("res/images/interface/UI-elementos.png");
    
}

void 
Interface::draw_self()
{
    Environment* env = Environment::get_instance();	

	int life;
	double sw = env->canvas->w();
	double sh = env->canvas->h();
	Object* main_char = m_gc->get_main_char();

	if (!main_char->id().compare("inti"))
	{
		Inti* inti = (Inti*) main_char;
		life = inti->life()->life();
		env->canvas->draw(ui_elements.get(),m_inti,env->camera->x(),env->camera->y());
	}
	else 
	{
		Inti* inti = (Inti*) main_char;
		life = inti->life()->life();
		env->canvas->draw(ui_elements.get(),m_killa,env->camera->x(),env->camera->y());
	}
	for(int i=0;i<life;i++)
		env->canvas->draw(ui_elements.get(),m_life_bar,env->camera->x()+155+(i*47),env->camera->y()+35);
}

void 
Interface::update_self(unsigned long elepsed)
{
}
