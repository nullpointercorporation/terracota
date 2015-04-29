#ifndef TERRACOTA_GAME_H
#define TERRACOTA_GAME_H

#include "game.h"

class Terracota : public Game
{
public:
    Terracota();

private:
    Level * load_level(const string& id);
};

#endif

