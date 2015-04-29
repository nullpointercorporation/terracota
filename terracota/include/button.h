#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "rect.h"
#include "object.h"

using std::string;

class Image;
enum Type { IDLE,ON_HOVER};

class Button : public Rect, Object
{
public:
    Button(const string& id, Object * parent,
           double x, double y, double w, double h,
           const string& idle_image, const string& on_hover_image);
    ~Button();

    void on_hover(double x, double y);

    void update_self(unsigned long elapsed);
    void draw_self();
private:
    Image * im_idle;
    Image * im_hover;
    int type; 
};

#endif
