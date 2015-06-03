#ifndef H_TERRACOTA_H
#define H_TERRACOTA_H

#include <core/game.h>
#include <core/keyboardevent.h>

class Terracota : public Game
{
public:
    Terracota();
    bool on_event(const KeyboardEvent& event);
private:
    Level* load_level(const string& id);
};

#endif
