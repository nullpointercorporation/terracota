#include "character.h"
#include "keyboardevent.h"

bool
Character::onKeyboardEvent(const KeyboardEvent& event)
{
	switch(event.state())
	{
	case KeyboardEvent::PRESSED:
		switch(event.key())
		{
			case KeyboardEvent::LEFT:
				m_speed_x -= speed[0]; 
				return true;
			case KeyboardEvent::RIGHT:
				m_speed_x += speed[0]; 
				return true;
			case KeyboardEvent::UP:
				m_speed_y -= speed[1]; 
				 return true;
			case KeyboardEvent::DOWN:
				m_speed_y += speed[1]; 
			     return true;
			default: 
				return false;
		}
		break;
	case KeyboardEvent::RELEASED:
       switch (event.key())
        {
        case KeyboardEvent::LEFT:
        case KeyboardEvent::RIGHT:
			m_speed_x = 0;	
			return true;
        case KeyboardEvent::UP:
        case KeyboardEvent::DOWN:
			m_speed_y = 0;
            return true;
        default:
            return false;
        }
	default:
			return false;	
	}


	return false;
}

bool
Character::onJoyStickEvent(const JoyStickEvent& event)
{
	return false;
}


