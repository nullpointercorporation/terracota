#include "life.h"


Life::Life(int life,unsigned long life_regen)
	: m_life(life),m_max_life(life),m_life_regen(life_regen),m_last(0)
{
}

Life::~Life()
{
}

void
Life::set_life(int life)
{
	m_life = life;
}

void 
Life::damage(int life)
{
	m_life -= life;
	if (m_life < 0) m_life = 0;
}

void 
Life::update_life(unsigned long elapsed)
{
	if (not m_last) m_last = elapsed;

	if ( elapsed -  m_last >= m_life_regen )
	{
		m_life++;	
		if (m_life > m_max_life)
			m_life = m_max_life;
	}
}
