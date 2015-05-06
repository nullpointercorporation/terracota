#ifndef STAGE_H
#define STAGE_H

#include "level.h"
#include "character.h"

class Stage : public Level
{
public:
    Stage(ObjectID id);

private:
    void draw_self();
};

#endif
