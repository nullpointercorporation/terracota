#ifndef H_BUTTON_H
#define H_BUTTON_H

#include <core/object.h>
#include <core/mousebuttonevent.h>
#include <core/mousemotionevent.h>

#include <core/image.h>
#include <core/texture.h>
#include <memory>

using std::shared_ptr;
using std::string;

typedef enum  { IDLE, ON_HOVER, HIDE } State;


class Button : public Object, public MouseButtonEvent, MouseMotionEvent
{
public:
    Button(Object* parant = nullptr, ObjectID id = "",const string& image= "",
           double x = 0, double y =0, double w = 100, double h = 100);
    ~Button();
    bool onMouseButtonEvent(const MouseButtonEvent& event);
    bool onMouseMotionEvent(const MouseMotionEvent& event);

    static ActionID clickedID;
	void set_hide();
	void set_show();

private:
    shared_ptr<Texture>  m_image;
    State m_state;
    void draw_self();
};

#endif
