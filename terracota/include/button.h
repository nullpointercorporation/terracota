#ifndef H_BUTTON_H
#define H_BUTTON_H

#include <core/object.h>
#include <core/mousebuttoneventlistener.h>
#include <core/mousemotioneventlistener.h>

#include <core/image.h>
#include <core/texture.h>
#include <core/listener.h>
#include <memory>

using std::shared_ptr;
using std::string;

typedef enum  { IDLE, ON_HOVER, HIDE } State;


class Button : public Object, Listener 
{
public:
    Button(Object* parant = nullptr, ObjectID id = "",const string& image= "",
           double x = 0, double y =0, double w = 100, double h = 100);
    ~Button();
    bool on_event(const MouseButtonEvent& event);
    bool on_event(const MouseMotionEvent& event);

    static ActionID clickedID;
	void set_hide();
	void set_show();

private:
    shared_ptr<Texture>  m_image;
    State m_state;
    void draw_self();
};

#endif
