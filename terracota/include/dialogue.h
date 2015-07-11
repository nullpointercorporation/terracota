#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <core/object.h>
#include <core/texture.h>
#include <memory>

using std::shared_ptr;

class Dialogue : public Object
{
public:
	Dialogue(Object* parent,ObjectID id,const string& file);
    ~Dialogue();
    void show_quest();
	void draw_self();
	void update_self(unsigned long elapsed);
private:
	shared_ptr<Texture> m_texture;
    bool hide;
};

#endif
