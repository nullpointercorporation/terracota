#include "battle_manager.h"
#include "inti.h"
#include "killa.h"
#include "life.h"
#include "enime.h"
#include <iostream>
using namespace std;

static BattleManager* instance = nullptr;

BattleManager* 
BattleManager::get_instance()
{
	if (not instance)
		instance = new BattleManager();
	return instance;
}

void 
BattleManager::set_map(Map* mapa)
{
	m_children.clear();
	m_target= mapa;
}


void 
BattleManager::remove_children()
{
	for (auto x: m_children)
	{
		m_target->remove_child(x);
	}
}


void 
BattleManager::fight(Object* object, ObjectID enime_id)
{
    Inti* inti;
	Killa* killa;
	Enime* enime;

	if ( m_children.empty())
	{
		m_children=m_target->children();
	}

	for (auto x : m_children )
	{
		if ( x->id() == enime_id  ){
			enime = (Enime*)x;
			break;
		}
	}

	cout << enime_id << endl;
	if (  object->id() == "inti"  )
	{
		
		inti = (Inti*) object;
		if ( inti->state_id() != Inti::ATTACKING )
		{
			inti->life()->damage(enime->force());	
			if (  enime->x() < object->x() )
				object->set_x(enime->x() + enime->w()+5);
			else
				object->set_x(enime->x()-object->w()-5);
		}
		else
		{
			enime->damage(1);
		}
	}
	else if ( object->id() == "killa" )
	{
		killa = (Killa*) object;
		if ( killa->state_id() != Killa::ATTACKING ){
			killa->life()->damage(1);
			if (  enime->x() < object->x() )
				object->set_x(enime->x() + enime->w()+5);
			else
				object->set_x(enime->x()-object->w()-5);
		}
		else
		{
			enime->damage(1);
		}
	}
}

BattleManager::BattleManager()
	: m_target(nullptr)
{
}

BattleManager::~BattleManager()
{
}
