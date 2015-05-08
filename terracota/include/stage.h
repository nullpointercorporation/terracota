#ifndef STAGE_H
#define STAGE_H

#include "level.h"
#include "image.h"
#include "rect.h"

#include <memory>

using std::string;
using std::shared_ptr;

class Stage : public Level
{
public:
    Stage(ObjectID id,const string& background, double x, double y, double w,double h);

private:
    shared_ptr<Image> m_background;
    void draw_self();
	Rect m_rect;
};

#endif
