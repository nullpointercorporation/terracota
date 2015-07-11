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
    NPC(Object* parent=nullptr,ObjectID id="npc",const string& file="",int dialogue=0);
    ~NPC();
    void draw_self();
    void update_self(unsigned long elapsed);
private:
   shared_ptr<Texture> m_texture;
   int m_dialogue;
};


#endif
