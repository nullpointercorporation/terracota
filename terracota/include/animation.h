#ifndef H_ANIMATION_H
#define H_ANIMATION_H

#include "rect.h"
#include <string>
using std::string;

class Image;

class Animation
{
public:
    Animation(const string& sprites,double x = 0,double y=0,double w=10,double h=10,
              int frames=4);
    ~Animation();
    void update();
    void changeAnimation(int number);
    void draw(double x, double y);
	void update(unsigned long elapsed);

    double x();
    double y();
    double w();
    double h();
private:
    double m_x,m_y,m_h,m_w;
    Image* m_sprites;
    int m_frames;
    int current_frame;
    Rect m_clip;
	unsigned long m_start;	
};

#endif
