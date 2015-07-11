#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <core/object.h>
#include <core/texture.h>

class Dialogue : public Object
{
public:
	Dialogue(Object* parent,ObjectID id,const string& file,double x,double y,double w,double h, int size);

	void draw_self();
	void update_self(unsigned long elapsed);
private:
	shared_ptr<Texture> m_image;
	Rect m_rect;
	int m_size;
};

#endif
