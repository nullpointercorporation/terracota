#ifndef H_GAME_OVER_H
#define H_GAME_OVER_H

#include <core/level.h>
#include <core/image.h>

#include <memory>

using std::shared_ptr;

class Image;

class GameOver: public Level
{
public:
    GameOver();
    ~GameOver();

	bool on_message(Object* sender, MessageID id, Parameters parameters);
private:
	shared_ptr<Texture> m_background;
	void draw_self();
};
#endif
