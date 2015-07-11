#ifndef DIALOGUE_MANAGER_H
#define DIALOGUE_MANAGER_H

#include "dialogue.h"
#include <list>

class DialogueManager
{
public:
	static DialogueManager* get_instance();
	void start_dialogue();
	void change_dialogue();
	DialogueManager();
	~DialogueManager();
private:
	int m_current_dialogue;	
	Dialogue* m_dialogue;	
};
#endif
