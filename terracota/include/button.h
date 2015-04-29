#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "rect.h"
#include "object.h"

#include "mousebuttonevent.h"
#include "mousemotionevent.h"
#include "mousebuttoneventlistener.h"
#include "mousemotioneventlistener.h"

using std::string;

class Image;
typedef enum{ IDLE,ON_HOVER, SELECTED} Type ;

class Button : public Rect, Object, 
                      MouseButtonEventListener,MouseMotionEventListener
{
public:
    Button(const string& id, Object * parent,
           double x, double y, double w, double h,
           const string& idle_image = "", 
           const string& on_hover_image = "",
           const string& selected_image = "");
    ~Button();

    void on_hover(double x, double y);
    void selected(double x , double y);

    bool onMouseButtonEvent(const MouseButtonEvent& event);
    bool onMouseMotionEvent(const MouseMotionEvent& event);
    void update_self(unsigned long elapsed);
    void draw_self();
private:
    Image * im_idle;
    Image * im_hover;
    Image * im_selected;
    int type; 
};

#endif
