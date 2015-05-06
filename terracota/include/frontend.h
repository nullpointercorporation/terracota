#ifndef H_FRONT_END_H
#define H_FRONT_END_H

#include "level.h"

#include "mousebuttoneventlistener.h"
#include "joystickeventlistener.h"
#include "keyboardeventlistener.h"

#include <memory>
using std::shared_ptr;

class Image;

class FrontEnd : public Level, MouseButtonEventListener, JoyStickEventListener,KeyboardEventListener
{
public:
	FrontEnd(const string& next, const string& image,
			 unsigned long duration = 3000 );
	virtual ~FrontEnd();

	bool onMouseButtonEvent(const MouseButtonEvent& event);
	bool onKeyboardEvent(const KeyboardEvent& event);
	bool onJoyStickEvent(const JoyStickEvent& event);

private:
	shared_ptr<Image> m_image;
	unsigned long m_start;
	unsigned long m_duration;
	int m_x,m_y;

	void update_self(unsigned long elapsed);
	void draw_self();
};

#endif
