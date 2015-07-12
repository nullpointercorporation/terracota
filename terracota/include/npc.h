#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <core/object.h>
#include <core/texture.h>
#include <core/environment.h>

using std::shared_ptr;

class NPC: public Object
{
public:
    NPC(Object* parent,ObjectID id,const string& file);
    ~NPC();
    void draw_self();
    void update_self(unsigned long elapsed);
private:
   shared_ptr<Texture> m_texture;
};


#endif
