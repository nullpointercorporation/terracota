#ifndef DIALOGUE_MANAGER_H
#define DIALOGUE_MANAGER_H

#include "dialogue.h"
#include "map.h"
#include <core/settings.h>
#include <core/environment.h>
#include <map>

using std::shared_ptr;

class DialogueManager
{
public:
	static DialogueManager* get_instance();
    void next_dialogue(const string& id);
	void set_map(Map* map);
	void generate_dialogue();
	void add_dialogue(const string& id);
	void add_children(list<Object *> children );
	void remove_children();
	list<string> make_list(const string& text);
	DialogueManager();
	~DialogueManager();
private:
	shared_ptr<Settings> m_settings;
	std::map <string , Dialogue* > m_dialogues;	
	Map* m_map;
};
#endif
