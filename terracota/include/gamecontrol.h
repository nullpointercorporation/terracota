#ifndef H_GAMECONTROL_H
#define H_GAMECONTROL_H

#include <core/sprite.h>

#include <core/object.h>
#include <core/keyboardeventlistener.h>
#include <core/mousebuttoneventlistener.h>
#include <core/mousemotioneventlistener.h>
#include <core/joystickeventlistener.h>

class Inti;
class KeyboardEvent;
class MouseButtonEvent;
class MouseMotionEvent;
class JoystickEvent;

class GameControl: public Object, KeyboardEventListener,
                          MouseButtonEventListener,
                          MouseMotionEventListener,
                          JoyStickEventListener
{
public:
    GameControl(Object *parent, ObjectID id);
    ~GameControl();

    bool onKeyboardEvent(const KeyboardEvent& event);
    bool onMouseButtonEvent(const MouseButtonEvent& event);
    bool onMouseMotionEvent(const MouseMotionEvent& event);
    bool onJoyStickEvent(const JoyStickEvent& event);
private:
    Inti* m_inti; 
    Inti* m_inti2; 
};

#endif
