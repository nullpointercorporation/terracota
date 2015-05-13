#include "gameflow.h"

static GameFlow* m_instance = nullptr;

GameFlow*
GameFlow::get_instance()
{
	if (not m_instance)
	{
		m_instance = new GameFlow();
	}
	return m_instance;
}

void 
GameFlow::release_game_flow()
{
	delete m_instance;
}


void 
GameFlow::set_state(GameState next)
{
	m_current_state = next; 
}

GameState
GameFlow::state()
{
	return m_current_state;
}

GameFlow::GameFlow()
{
	m_current_state = FRONT_END;
}
