#ifndef H_TERRACOTA_H
#define H_TERRACOTA_H

#include <game.h>
#include <keyboardevent.h>

class Terracota : public Game
{
public:
    Terracota();
    bool onKeyboardEvent(const KeyboardEvent& event);
private:
    Level* load_level(const string& id);
};

#endif
