#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <core/object.h>
#include <core/texture.h>
#include <memory>

using std::shared_ptr;

class Dialogue : public Object
{
public:
	Dialogue(Object* parent,ObjectID id,const string& file,unsigned long time, const string& next_id,Object* speaking,double x,double y);
    ~Dialogue();
    void show_quest();
	void draw_self();
	void update_self(unsigned long elapsed);
	void set_speaker(Object* speaker);
	Object* speaker();
private:
	shared_ptr<Texture> m_texture;
    bool hide;
    string m_id;
    unsigned long m_time,m_start;
    Object* m_speaking;
    double m_x,m_y;
};

#endif
