#ifndef H_SETTINGS_H
#define H_SETTINGS_H


#include "level.h"
#include "image.h"

#include <memory>
using std::shared_ptr;

class Image;

class Settings : public Level
{
public:
	Settings();
	virtual ~Settings();
	
	bool on_message(Object* sender, MessageID id, Parameters parameters);

private:
	shared_ptr<Image> m_background;
	void draw_self();
};



#endif
