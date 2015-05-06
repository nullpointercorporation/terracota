#ifndef H_BUTTON_H
#define H_BUTTON_H

#include "object.h"
#include "mousebuttoneventlistener.h"
#include "mousemotioneventlistener.h"

#include "image.h"
#include <memory>

using std::shared_ptr;
using std::string;

typedef enum  { IDLE, ON_HOVER } State;


class Button : public Object, public MouseButtonEventListener, MouseMotionEventListener
{
public:
    Button(Object* parant = nullptr, ObjectID id = "",const string& image= "",
           double x = 0, double y =0, double w = 100, double h = 100);
    ~Button();
    bool onMouseButtonEvent(const MouseButtonEvent& event);
    bool onMouseMotionEvent(const MouseMotionEvent& event);

    static ActionID clickedID;

private:
    shared_ptr<Image>  m_image;
    State m_state;
    void draw_self();
};

#endif
