#ifndef H_SETTINGS_H
#define H_SETTINGS_H


#include "level.h"

class Image;

class Settings : public Level
{
public:
	Settings();
	virtual ~Settings();
	
	bool on_message(Object* sender, MessageID id, Parameters parameters);

private:
	void draw_self();
};



#endif
