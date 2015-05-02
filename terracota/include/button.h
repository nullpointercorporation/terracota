#ifndef H_BUTTON_H
#define H_BUTTON_H

#include "object.h"
#include "mousebuttoneventlistener.h"

#include <memory>
#include "color.h"

using std::unique_ptr;


class Button : public Object, public MouseButtonEventListener
{
public:
    Button(Object* parant = nullptr, ObjectID id = "",
           double x = 0, double y =0, double w = 100, double h = 100,
           const Color& background = Color::BLUE);
    ~Button();
    bool onMouseButtonEvent(const MouseButtonEvent& event);

    static ActionID clickedID;

private:
    class Impl;
    unique_ptr<Impl> m_impl;

    void draw_self();
};

#endif
