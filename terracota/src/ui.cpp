#include <ui.h>
#include "inti.h"
#include "killa.h"
#include "life.h"

Interface::Interface(Object * parent, ObjectID id, GameControl* gc)
	: Object(parent,id),ui_elements(nullptr),
	  m_killa (Rect(0, 6, 370, 140)), 
	  m_inti(Rect(0, 162, 370, 144)),
	  m_button(Rect(0,320,100,100)),
	  m_life_bar(Rect(26,425,33,38)),
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
	Object* main_char = m_gc->get_main_char();

    double x = env->camera->x();
    double y = env->camera->y();

	if (!main_char->id().compare("inti"))
	{
		Inti* inti = (Inti*) main_char;
		life = inti->life()->life();
		env->canvas->draw(ui_elements.get(), m_inti, x, y, m_inti.w(), m_inti.h());
        y += 50;
	}
	else 
	{
		Killa* killa = (Killa*) main_char;
		life = killa->life()->life();
		env->canvas->draw(ui_elements.get(), m_killa, x, y, m_killa.w(), m_killa.h());
        y += 46;
	}

    x += 137;
    double dx = 4;

	for(int i=0;i<life;i++)
		env->canvas->draw(ui_elements.get(), m_life_bar, x + i*(m_life_bar.w() + dx), y, m_life_bar.w(), m_life_bar.h());
}

void 
Interface::update_self(unsigned long elepsed)
{
}
