#ifndef MENU_H
#define MENU_H


#include "vector"
#include "level.h"

class Image;

class Menu : public Level
{
public:
    Menu(const string& next, const string& background);
	~Menu();
    void create_buttons();
private:
   Image* m_background;
   void draw_self();
};


#endif
