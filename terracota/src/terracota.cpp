#include "game.h"
#include "terracota.h"
#include "environment.h"

Terracota::Terracota() throw (Exception) 
	: is_fullscreen(false), width(640),height(480) 
{
	env = Environment::get_instance();
}

void 
Terracota::process_input(){
	
	SDL_Event event;

	while(SDL_PollEvent(&event))
	{
		 env->video->clear();
		 if (event.type == SDL_QUIT)
            {
                m_done = true;
            }
	}
}
