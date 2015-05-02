#ifndef H_TERRACOTA_H
#define H_TERRACOTA_H

#include "game.h"

class Terracota : public Game
{
public:
    Terracota();

private:
    Level* load_level(const string& id);
};

#endif
