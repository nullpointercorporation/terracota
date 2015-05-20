#ifndef H_TITLE_SCREEN_H
#define H_TITLE_SCREEN_H

#include <core/level.h>
#include <core/image.h>
#include <memory>

using std::shared_ptr;
class Image;

class TitleScreen : public Level
{
public:
	TitleScreen();
	virtual ~TitleScreen();
	
	bool on_message(Object* sender, MessageID id, Parameters parameters);

private:
	shared_ptr<Texture> m_background;	
	void draw_self();
};

#endif
