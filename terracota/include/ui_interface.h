#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <core/object.h>
#include "life.h"
#include <memory>
#include <core/texture.h>
#include <core/rect.h>
#include <core/environment.h>

using std::shared_ptr;

class UI : public Object
{
public:
    UI(Object* parent, ObjectID id);
    ~UI();

    void update_self(unsigned long elapsed);
    void draw_self(); 
private:
    shared_ptr<Texture> m_ui;
    Rect crop_inti_ui,crop_killaui,crop_life,
    crop_change_char,crop_change_button;
};



#endif
