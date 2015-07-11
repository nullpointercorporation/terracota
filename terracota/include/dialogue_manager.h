#ifndef DIALOGUE_MANAGER_H
#define DIALOGUE_MANAGER_H

class DialogueManager
{
public:
	static DialogueManager* get_instance();

private:
	DialogueManager();
};
#endif
