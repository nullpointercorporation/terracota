#ifndef LIFE_H
#define LIFE_H

class Life
{
public:
	Life(int life = 6, unsigned long life_regen=500);
	~Life();
	void update_life(unsigned long elapsed);

	void set_life(int life);
	void damage(int life);
	int life();

private:
	int m_life;
	int m_max_life;
	unsigned long m_life_regen;
	unsigned long m_last;
};


#endif 
