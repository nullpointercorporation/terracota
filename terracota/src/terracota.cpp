#include "game.h"
#include "terracota.h"
#include "environment.h"
#include "input.h"

Terracota::Terracota() throw (Exception) 
	: is_fullscreen(false), width(640),height(480) 
{
	env = Environment::get_instance();
}

void 
Terracota::process_input()
{
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		Input::Instance()->handle(event);
		m_done = Input::Instance()->hasQuit();
	}
}

void
draw(){
	
}

