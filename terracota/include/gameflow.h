#ifndef H_GAME_FLOW_H
#define H_GAME_FLOW_H

typedef enum _GameState {
	FRONT_END,
	MENU,
	SETTINGS,
	PLAYING,
	STOPPED,
	TOTAL_STATES
} GameState;

class GameFlow
{
public:
	static GameFlow* get_instance();
	static void release_game_flow();
	
	void set_state(GameState next);
	GameState state();
private:
	GameState m_current_state;
	GameFlow();
};

#endif
