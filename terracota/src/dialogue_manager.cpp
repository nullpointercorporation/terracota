#include "dialogue_manager.h"

static DialogueManager* instance=nullptr;

DialogueManager* get_instance()
{
	if (not instance)
	{
		instance = new DialogueManager(); 
	}
	return instance;
}

DialogueManager::DialogueManager()
	: m_current_dialogue(0),m_dialogue(nullptr)
{
}

DialogueManager::~DialogueManager()
{
}

void 
DialogueManager::start_dialogue()
{
}

void 
DialogueManager::change_dialogue()
{
}
