#ifndef H_GAME_OVER_H
#define H_GAME_OVER_H

#include "level.h"
#include "image.h"

#include <memory>

using std::shared_ptr;

class Image;

class GameOver: public Level
{
    GameOver();
    ~GameOver();

	bool on_message(Object* sender, MessageID id, Parameters parameters);
private:
	shared_ptr<Image> m_background;
	void draw_self();
};
#endif
