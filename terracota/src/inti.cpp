#include "inti.h"
#include <core/environment.h>
#include <core/keyboardevent.h>
#include <iostream>

using namespace std;

using std::make_pair;
class Inti::Impl
{
public:
	Impl(Inti* inti)
		: m_inti(inti), m_direction(Inti::LEFT),m_moviment(make_pair(0.0, 0.0))
	{
	}
    Direction direction() const { return m_direction; }
    void set_direction(Direction direction) { m_direction = direction; }

    const pair<double, double>& moviment() const { return m_moviment; }

    void set_moviment(double xaxis, double yaxis)
    {
        m_moviment = make_pair(xaxis, yaxis);
    }

private:
	Inti* m_inti;
    Direction m_direction;
    pair<double, double> m_moviment;
};



class Idle : public SpriteState
{
public:
    Idle(Inti *inti)
        : m_inti(inti), m_animation(new Animation("res/images/characters/inti/idle_1.png",
            0, 0, 127, 172, 24, 50, true)), m_left(0), m_right(0),m_up(0),m_down(0),m_attack(0)
    {
    }

    ~Idle() {}

    void enter(int)
    {
        m_inti->set_dimensions(m_animation->w(), m_animation->h());
        m_right = m_left = m_up = m_down = m_attack= 0;
    }

    void leave(int)
    {
    }
   void draw()
    {
        m_animation->draw(m_inti->x(), m_inti->y());
    }

    void update(unsigned long elapsed)
    {
        short xres = m_right - m_left;
        short yres = m_down - m_up;

        if (xres < 0)
        {
            m_inti->set_moviment(-1.0, 0.0);
            m_inti->set_direction(Inti::LEFT);
            m_inti->report_event(Inti::MOVED);
        } 
        else if (xres > 0)
        {
            m_inti->set_moviment(1.0, 0.0);
            m_inti->set_direction(Inti::RIGHT);
            m_inti->report_event(Inti::MOVED);
        }

        if (yres > 0)
        {
            m_inti->set_moviment(0.0,-1.0);
            m_inti->set_direction(Inti::DOWN);
            m_inti->report_event(Inti::MOVED);
        }

        else if(yres < 0)
        {
            m_inti->set_moviment(0.0,1.0);
            m_inti->set_direction(Inti::UP);
            m_inti->report_event(Inti::MOVED);
        }
		if ( m_attack > 0)
		{
            m_inti->report_event(Inti::ATTACKED);
		}

        Inti::Direction dir = m_inti->direction();
        int row = dir == Inti::LEFT ? 1 : 0;
        m_animation->set_row(row);
        m_animation->update(elapsed);
    }

    bool onKeyboardEvent(const KeyboardEvent& event)
    {
        switch (event.state())
        {
        case KeyboardEvent::PRESSED:
            switch (event.key())
            {
            case KeyboardEvent::LEFT:
            case KeyboardEvent::A:
                m_left = 1;
                return true;
            case KeyboardEvent::UP:
            case KeyboardEvent::W:
                m_up = 1;
                return true;
            case KeyboardEvent::RIGHT:
            case KeyboardEvent::D:
                m_right = 1;
                return true;
            case KeyboardEvent::DOWN:
            case KeyboardEvent::S:
                m_down = 1;
                return true;
            case KeyboardEvent::SPACE:
				m_attack = 1;
                return true;
            default:
                break;
            }
            break;

        case KeyboardEvent::RELEASED:
            switch (event.key())
            {
            case KeyboardEvent::LEFT:
            case KeyboardEvent::A:
                m_left = 0;
                return true;
            case KeyboardEvent::UP:
            case KeyboardEvent::W:
                m_up = 0;
                return true;
            case KeyboardEvent::RIGHT:
            case KeyboardEvent::D:
                m_right = 0;
                return true;
            case KeyboardEvent::DOWN:
            case KeyboardEvent::S:
                m_down = 0;
                return true;
            case KeyboardEvent::SPACE:
				m_attack = 0;
                return true;
            default:
                break;
            }
            break;
        }

        return false;
    }

private:
    Inti *m_inti;
	
    unique_ptr<Animation> m_animation;
    int m_left, m_right,m_up,m_down;
	int m_attack;
};

class Attacking: public SpriteState
{
public:
    Attacking(Inti *inti)
       : m_inti(inti),m_animation(
        new Animation("res/images/characters/inti/attack_1.png",0,0,174,224,12,50,true)),
        m_left(0),m_right(0),m_down(0),m_up(0),m_attack(0),m_last(0)
    {
    }

    ~Attacking(){}

    const double speed = 0.5;

    void enter(int from)
    {
		m_inti->set_position(m_animation->w(),m_animation->h()-52);
        m_inti->set_dimensions(m_animation->w(), m_animation->h());

        Inti::Direction dir = m_inti->direction();

        m_right = dir == Inti::RIGHT ? 1 : 0;
        m_left = dir == Inti::LEFT ? 1 : 0;
        m_up = dir == Inti::UP ? 1 : 0;
        m_down = dir == Inti::DOWN ? 1 : 0;
		m_attack = 1;
        m_last = 0;
    }

    void leave(int)
    {
		m_inti->set_position(m_animation->w(),m_animation->h());
    }

    void draw()
    {   
        m_animation->draw(m_inti->x(), m_inti->y());
    }

    bool onKeyboardEvent(const KeyboardEvent& event)
    {
        switch (event.state())
        {
        case KeyboardEvent::PRESSED:
            switch (event.key())
            {
            case KeyboardEvent::SPACE:
				m_attack = 1;
                return true;
            default:
                break;
            }
            break;

        case KeyboardEvent::RELEASED:
            switch (event.key())
            {
            case KeyboardEvent::SPACE:
				m_attack = 0;
                return true;
            default:
                break;
            }
            break;
        }

        return false;
    }

    void update(unsigned long elapsed)
    {
		if (not m_attack )
		{
            m_inti->report_event(Inti::STOPPED);
		}
        Inti::Direction dir = m_inti->direction();
        int row = dir == Inti::LEFT ? 1 : 0;
        m_animation->set_row(row);
        m_animation->update(elapsed);
    }

private:
    Inti *m_inti;
    unique_ptr<Animation> m_animation;
    short m_left, m_right,m_down,m_up,m_attack;
    unsigned long m_last;
};



class Walking : public SpriteState
{
public:
    Walking(Inti *inti)
        : m_inti(inti), m_animation(
        new Animation("res/images/characters/inti/walking_1.png", 0, 0, 127, 177, 21, 50, true)),
        m_left(0), m_right(0),m_down(0),m_up(0),m_last(0)
    {
    }

    ~Walking() {}

    const double speed = 160.0;

    void enter(int from)
    {
        m_inti->set_dimensions(m_animation->w(), m_animation->h());

        Inti::Direction dir = m_inti->direction();

        m_right = dir == Inti::RIGHT ? 1 : 0;
        m_left = dir == Inti::LEFT ? 1 : 0;
        m_up = dir == Inti::UP ? 1 : 0;
        m_down = dir == Inti::DOWN ? 1 : 0;
        m_last = 0;

        if (from == Inti::IDLE)
        {
            auto moviment = m_inti->moviment();
            double x = moviment.first * speed;
            double y = moviment.second * speed;
            m_inti->set_moviment(x, y);
        }
    }

    void leave(int)
    {
    }

    void draw()
    {   
        m_animation->draw(m_inti->x(), m_inti->y());
    }

    bool onKeyboardEvent(const KeyboardEvent& event)
    {
        switch (event.state())
        {
        case KeyboardEvent::PRESSED:
            switch (event.key())
            {
            case KeyboardEvent::LEFT:
            case KeyboardEvent::A:
                m_left = 1;
                return true;
            case KeyboardEvent::UP:
            case KeyboardEvent::W:
                m_up = 1;
                return true;
            case KeyboardEvent::RIGHT:
            case KeyboardEvent::D:
                m_right = 1;
                return true;
            case KeyboardEvent::DOWN:
            case KeyboardEvent::S:
                m_down = 1;
                return true;
            default:
                break;
            }
            break;

        case KeyboardEvent::RELEASED:
            switch (event.key())
            {
            case KeyboardEvent::LEFT:
            case KeyboardEvent::A:
                m_left = 0;
                return true;
            case KeyboardEvent::UP:
            case KeyboardEvent::W:
                m_up = 0;
                return true;
            case KeyboardEvent::RIGHT:
            case KeyboardEvent::D:
                m_right =0;
                return true;
            case KeyboardEvent::DOWN:
            case KeyboardEvent::S:
                m_down = 0;
                return true;
            default:
                break;
            }
            break;
        }

        return false;
    }

    void update(unsigned long elapsed)
    {
        short xres = m_right - m_left;
        short yres = m_down -  m_up ;

        if (xres < 0)
        {
            m_inti->set_direction(Inti::LEFT);
        } else if (xres > 0)
        {
            m_inti->set_direction(Inti::RIGHT);
        } 

            
        m_inti->set_moviment(xres*speed ,yres*speed);

        if (xres ==0 and  yres == 0)
        {
            m_inti->report_event(Inti::STOPPED);
        }

        Inti::Direction dir = m_inti->direction();
        int row = dir == Inti::LEFT ? 0 : 1;
        m_animation->set_row(row);

        if (not m_last)
        {
            m_last = elapsed;
        }

        auto moviment = m_inti->moviment();
        unsigned long delta = elapsed - m_last;
        double x = m_inti->x() + (moviment.first * delta)/1000.0;
        double y = m_inti->y() + (moviment.second * delta)/1000.0;
        m_inti->set_x(x);
        m_inti->set_y(y);

        m_last = elapsed;
        m_animation->update(elapsed);
    }

private:
    Inti *m_inti;
    unique_ptr<Animation> m_animation;
    short m_left, m_right,m_down,m_up;
    unsigned long m_last;
};

Inti::Inti(Object *parent, const string& id)
    : Sprite(parent, id), m_impl(new Inti::Impl(this))
{
    add_state(IDLE, new Idle(this));
    add_state(WALKING, new Walking(this));
	add_state(ATTACKING,new Attacking(this));

	/* to action*/
    add_transition(MOVED, IDLE, WALKING);
    add_transition(ATTACKED, IDLE, ATTACKING);
	/* to stop*/
    add_transition(STOPPED, WALKING, IDLE);
    add_transition(STOPPED, ATTACKING, IDLE);
    change_state(IDLE, NONE);

    Environment *env = Environment::get_instance();
    env->events_manager->register_keyboard_event_listener(this);
}

Inti::~Inti()
{
    Environment *env = Environment::get_instance();
    env->events_manager->unregister_keyboard_event_listener(this);
}

Inti::Direction
Inti::direction() const
{
    return m_impl->direction();
}

void
Inti::set_direction(Direction direction)
{
    m_impl->set_direction(direction);
}

const pair<double, double>&
Inti::moviment() const
{
    return m_impl->moviment();
}

void
Inti::set_moviment(double xaxis, double yaxis)
{
    m_impl->set_moviment(xaxis, yaxis);
}
