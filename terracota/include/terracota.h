#ifndef TERRACOTA_H
#define TERRACOTA_H

#include "game.h"

class Environment;
class Exception;

class Terracota: public Game
{
public:
	Terracota() throw (Exception) ;
private:
	void process_input();

	bool is_fullscreen;
	int width,height;
	Environment *env;
};
#endif

