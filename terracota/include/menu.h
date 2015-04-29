#ifndef MENU_H
#define MENU_H


#include "vector"
#include "level.h"
#include "mousebuttoneventlistener.h"
#include "mousemotioneventlistener.h"

class Image;

class Menu : public Level,MouseButtonEventListener,MouseMotionEventListener
{
public:
    Menu(const string& next, const string& background);
	~Menu();
    bool onMouseButtonEvent(const MouseButtonEvent& event);
    bool onMouseMotionEvent(const MouseMotionEvent& event);
    void create_buttons();
private:
   Image* m_background;
   void draw_self();
};


#endif
