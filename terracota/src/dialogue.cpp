#include "dialogue.h"
#include <core/environment.h>
#include "dialogue_manager.h"
#include <iostream>
using namespace std;

Dialogue::Dialogue(Object* parent,ObjectID id,const string& file,unsigned long time,const string& next_id,Object* speaking,double x,double y,const string&speaker_id)
	:Object(parent,id),m_texture(nullptr),hide(true),m_id(next_id), m_speaking(speaking),m_x(x),m_y(y),m_speaker_id(speaker_id)
{
	Environment* env = Environment::get_instance();
	m_texture = env->resources_manager->get_texture(file);
	m_time = time;
	m_start = 0;
}

Dialogue::~Dialogue()
{
}

void 
Dialogue::show_quest()
{
	hide = false;
}

void 
Dialogue::draw_self()
{
	if(not hide)
	{
		Environment* env = Environment::get_instance();

		cout <<  m_speaking->x() << "x" << m_speaking->y()<<endl;
			env->canvas->draw(m_texture.get(),
			m_speaking->x()+m_x,m_speaking->y()-m_y);
	}
}

void 
Dialogue::update_self(unsigned long elapsed)
{
	unsigned long delta=0;
	if (m_start == 0 && not hide) m_start = elapsed;
	delta = elapsed - m_start;
	if (delta > m_time && not hide)
	{
		DialogueManager::get_instance()->next_dialogue(m_id);
		m_start = 0;
		hide = true;
	}
}
	

string 
Dialogue::speaker_id()
{
	return m_speaker_id;
}


void 
Dialogue::set_speaker(Object* speaker)
{
	m_speaking= speaker;
}

Object*
Dialogue::speaker()
{
	return m_speaking;
}

