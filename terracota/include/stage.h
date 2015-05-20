#ifndef STAGE_H
#define STAGE_H

#include <core/level.h>
#include <core/image.h>
#include <core/rect.h>

#include <core/sprite.h>
#include <memory>

using std::string;
using std::shared_ptr;

class Stage : public Level
{
public:
    Stage(ObjectID id,const string& background, double x, double y, double w,double h);

private:
    shared_ptr<Texture> m_background;
    void draw_self();
	Rect m_rect;
};

#endif
