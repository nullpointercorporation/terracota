#include "inti.h"
#include <core/rect.h>
#include <core/environment.h>
#include <core/keyboardevent.h>
#include <core/joystickevent.h>
#include <iostream>
#include "life.h"
#include "map.h"
#include <core/level.h>
#include "gamecontrol.h"

using namespace std;

using std::make_pair;
class Inti::Impl
{
public:
    Impl(Inti* inti)
        : m_inti(inti), m_direction(Inti::LEFT), m_moviment(make_pair(0.0, 0.0)),m_life(new Life())
    {
    }

    Direction direction() const { return m_direction; }
    void set_direction(Direction direction) { m_direction = direction; }

    const pair<double, double>& moviment() const { return m_moviment; }

    void set_moviment(double xaxis, double yaxis)
    {
        m_moviment = make_pair(xaxis, yaxis);
    }

    Life* life()
    {
        return m_life;
    }

    bool can_change(){
		return true;
	}

    bool on_message(Object *sender, MessageID id, Parameters p)
    {
        if (id == Object::hitID)
        {
        	GameControl* gamecontrol = GameControl::get_instance(); 
        	Rect r = Rect::from_parameters(p);
            if (sender->id()[0] == 'd')
            {
					Map* mapa = (Map*)gamecontrol->level();
					mapa->next_map(sender->id());
            }


			if (sender->id()[0] == 't')
			{
				m_inti->set_y(sender->y()+sender->h());
			}

            if (sender->id()[0] == 'c' )
            {
					if ( r.w() <= r.h() )
					{
						if ( sender->x() < m_inti->x() )	
						{
							m_inti->set_x(sender->x() + sender->w());
						}
						else
						{
							m_inti->set_x(sender->x() - m_inti->w());
						}
					}
					else
					{
						double delta1;
						delta1=  m_inti->y()+m_inti->h() - sender->y(); 

						if ( delta1  > sender->h()/2  )
						{	
							if (m_inti->y()+m_inti->h() < sender->y()+sender->h())
							{
									m_inti->set_y(sender->y()+sender->h() - m_inti->h());
							}
						}else{
							if (m_inti->y()+m_inti->h() > sender->y())
							{
									m_inti->set_y(sender->y() - m_inti->h());
							}
						}
					}
			}
            if (sender->id()[0] == 'n' )
            {
				cout << "NPC"<<sender->id() <<endl;
            }
        }

        return false;
    }

private:
    Inti* m_inti;
    Direction m_direction;
    pair<double, double> m_moviment;
    Life* m_life;
};

class Idle : public SpriteState
{
public:
    Idle(Inti *inti)
        : m_inti(inti), m_animation(new Animation("res/images/characters/inti/idle.png",
            0, 0, 120, 186, 24, 50, true)), m_left(0), m_right(0), m_up(0), m_down(0), m_attack(0), m_interacting(0)
    {
        m_inti->set_dimensions(m_animation->w(), m_animation->h());
    }

    ~Idle() {}

    void enter(int)
    {
        m_right = m_left = m_up = m_down = m_attack = m_interacting = 0;
        m_animation->reset();
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
            m_inti->set_moviment(0.0, -1.0);
            m_inti->set_direction(Inti::DOWN);
            m_inti->report_event(Inti::MOVED);
        }

        else if (yres < 0)
        {
            m_inti->set_moviment(0.0, 1.0);
            m_inti->set_direction(Inti::UP);
            m_inti->report_event(Inti::MOVED);
        }
        if ( m_attack > 0)
        {
            m_inti->report_event(Inti::ATTACKED);
        }


        if ( m_interacting > 0)
        {
            m_inti->report_event(Inti::INTERACTED);
        }

        Inti::Direction dir = m_inti->direction();
        int row = dir == Inti::LEFT ? 1 : 0;
        m_animation->set_row(row);
        m_animation->update(elapsed);
    }

    bool on_event(const KeyboardEvent& event)
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
            case KeyboardEvent::E:
            case KeyboardEvent::N:
                m_interacting = 1;
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
            case KeyboardEvent::E:
            case KeyboardEvent::N:
                m_interacting = 0;
            default:
                break;
            }
            break;
        }

        return false;
    }

    bool on_event(const JoyStickEvent& event)
    {
        switch (event.state())
        {
        case JoyStickEvent::PRESSED:
            switch (event.button())
            {
            case JoyStickEvent::UP:
                m_up = 1;
                return true;
            case JoyStickEvent::LEFT:
                m_left = 1;
                return true;
            case JoyStickEvent::RIGHT:
                m_right = 1;
                return true;
            case JoyStickEvent::DOWN:
                m_down = 1;
                return true;
            case JoyStickEvent::SQUARE:
                m_attack = 1;
                return true;
            case JoyStickEvent::X:
                m_interacting = 1;
            default:
                break;
            }
            break;

        case KeyboardEvent::RELEASED:
            switch (event.button())
            {
            case JoyStickEvent::UP:
                m_up = 0;
                return true;
            case JoyStickEvent::LEFT:
                m_left = 0;
                return true;
            case JoyStickEvent::RIGHT:
                m_right = 0;
                return true;
            case JoyStickEvent::DOWN:
                m_down = 0;
                return true;
            case JoyStickEvent::SQUARE:
                m_attack = 0;
                return true;
            case JoyStickEvent::X:
                m_interacting = 0;
            default:
                break;
            }
            break;
        }

        return false;
    }
	bool can_change(){
		return true; 
	}

private:
    Inti *m_inti;

    unique_ptr<Animation> m_animation;
    int m_left, m_right, m_up, m_down;
    int m_attack,m_interacting;
};

class Attacking: public SpriteState
{
public:
    Attacking(Inti *inti)
        : m_inti(inti), m_animation(
              new Animation("res/images/characters/inti/attack.png", 0, 0, 207, 260, 12, 50, true)),
          m_left(0), m_right(0), m_down(0), m_up(0), m_attack(0), m_last(0)
    {
    }

    ~Attacking() {}

    void enter(int from)
    {
        Inti::Direction dir = m_inti->direction();

        m_right = dir == Inti::RIGHT ? 1 : 0;
        m_left = dir == Inti::LEFT ? 1 : 0;
        m_up = dir == Inti::UP ? 1 : 0;
        m_down = dir == Inti::DOWN ? 1 : 0;
        m_attack = 1;
        m_last = 0;
        m_animation->reset();
    }

    void leave(int)
    {
    }

    void draw()
    {
        Inti::Direction dir = m_inti->direction();
        if (dir == Inti::LEFT)
            m_animation->draw(m_inti->x()-70, m_inti->y()-65);
        else
            m_animation->draw(m_inti->x()-10, m_inti->y()-65);
    }

    bool on_event(const KeyboardEvent& event)
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

    bool on_event(const JoyStickEvent& event)
    {
        switch (event.state())
        {
        case JoyStickEvent::PRESSED:
            switch (event.button())
            {
            case JoyStickEvent::SQUARE:
                m_attack = 1;
                return true;
            default:
                break;
            }
            break;

        case JoyStickEvent::RELEASED:
            switch (event.button())
            {
            case JoyStickEvent::SQUARE:
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
	bool can_change(){
		return false; 
	}

private:
    Inti *m_inti;
    unique_ptr<Animation> m_animation;
    short m_left, m_right, m_down, m_up, m_attack;
    unsigned long m_last;
};




class Interacting: public SpriteState
{
public:
    Interacting(Inti *inti)
        : m_inti(inti), m_animation(
              new Animation("res/images/characters/inti/interact.png", 0, 0, 128, 177, 18, 50, true)),
          m_left(0), m_right(0), m_down(0), m_up(0), m_interacting(0), m_last(0)
    {
    }

    ~Interacting() {}

    void enter(int from)
    {
        Inti::Direction dir = m_inti->direction();

        m_right = dir == Inti::RIGHT ? 1 : 0;
        m_left = dir == Inti::LEFT ? 1 : 0;
        m_up = dir == Inti::UP ? 1 : 0;
        m_down = dir == Inti::DOWN ? 1 : 0;
        m_interacting = 1;
        m_last = 0;
        m_animation->reset();
    }

    void leave(int)
    {
    }

    void draw()
    {
        m_animation->draw(m_inti->x(), m_inti->y());
    }

    bool on_event(const KeyboardEvent& event)
    {
        switch (event.state())
        {
        case KeyboardEvent::PRESSED:
            switch (event.key())
            {
            case KeyboardEvent::E:
            case KeyboardEvent::N:
                m_interacting = 1;
                return true;
            default:
                break;
            }
            break;

        case KeyboardEvent::RELEASED:
            switch (event.key())
            {
            case KeyboardEvent::E:
            case KeyboardEvent::N:
                m_interacting = 0;
                return true;
            default:
                break;
            }
            break;
        }

        return false;
    }

    bool on_event(const JoyStickEvent& event)
    {
        switch (event.state())
        {
        case JoyStickEvent::PRESSED:
            switch (event.button())
            {
            case JoyStickEvent::X:
                m_interacting = 1;
                return true;
            default:
                break;
            }
            break;

        case JoyStickEvent::RELEASED:
            switch (event.button())
            {
            case JoyStickEvent::X:
                m_interacting = 0;
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
        if (not m_interacting )
        {
            m_inti->report_event(Inti::STOPPED);
        }
        Inti::Direction dir = m_inti->direction();
        int row = dir == Inti::LEFT ? 1 : 0;
        m_animation->set_row(row);
        m_animation->update(elapsed);
    }
	bool can_change(){
		return false; 
	}

private:
    Inti *m_inti;
    unique_ptr<Animation> m_animation;
    short m_left, m_right, m_down, m_up, m_interacting;
    unsigned long m_last;
};




class Walking : public SpriteState
{
public:
    Walking(Inti *inti)
        : m_inti(inti), m_animation(
              new Animation("res/images/characters/inti/walking.png", 0, 0, 120, 186, 20, 50, true)),
          m_left(0), m_right(0), m_down(0), m_up(0), m_last(0)
    {
    }

    ~Walking() {}

    const double speed = 160.0;

    void enter(int from)
    {
        Inti::Direction dir = m_inti->direction();

        m_right = dir == Inti::RIGHT ? 1 : 0;
        m_left = dir == Inti::LEFT ? 1 : 0;
        m_up = dir == Inti::UP ? 1 : 0;
        m_down = dir == Inti::DOWN ? 1 : 0;
        m_last = 0;
        m_animation->reset();

        if (from == Inti::IDLE)
        {
            auto moviment = m_inti->moviment();
            double x = moviment.first * speed;
            double y = moviment.second * speed;
            m_inti->set_moviment(x, y);
			cout << m_inti->x() << "-"<<m_inti->y() << endl;
        }
    }

    void leave(int)
    {
    }

    void draw()
    {
        m_animation->draw(m_inti->x(), m_inti->y());
    }

    bool on_event(const KeyboardEvent& event)
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
                m_right = 0;
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

    bool on_event(const JoyStickEvent& event)
    {
        switch (event.state())
        {
        case JoyStickEvent::PRESSED:
            switch (event.button())
            {
            case JoyStickEvent::UP:
                m_up = 1;
                return true;
            case JoyStickEvent::LEFT:
                m_left = 1;
                return true;
            case JoyStickEvent::RIGHT:
                m_right = 1;
                return true;
            case JoyStickEvent::DOWN:
                m_down = 1;
                return true;
            default:
                break;
            }
            break;

        case KeyboardEvent::RELEASED:
            switch (event.button())
            {
            case JoyStickEvent::UP:
                m_up = 0;
                return true;
            case JoyStickEvent::LEFT:
                m_left = 0;
                return true;
            case JoyStickEvent::RIGHT:
                m_right = 0;
                return true;
            case JoyStickEvent::DOWN:
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


        m_inti->set_moviment(xres * speed, yres * speed);

        if (xres == 0 and  yres == 0)
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
        double x = m_inti->x() + (moviment.first * delta) / 1000.0;
        double y = m_inti->y() + (moviment.second * delta) / 1000.0;
        m_inti->set_x(x);
        m_inti->set_y(y);

        m_last = elapsed;
        m_animation->update(elapsed);
    }
	bool can_change(){
		return false; 
	}

private:
    Inti *m_inti;
    unique_ptr<Animation> m_animation;
    short m_left, m_right, m_down, m_up;
    unsigned long m_last;
};

Inti::Inti(Object *parent, const string& id)
    : Sprite(parent, id), m_impl(new Inti::Impl(this))
{
    add_state(IDLE, new Idle(this));
    add_state(WALKING, new Walking(this));
    add_state(ATTACKING, new Attacking(this));
    add_state(INTERACTING, new Interacting(this));

    /* to action*/
    add_transition(MOVED, IDLE, WALKING);
    add_transition(ATTACKED, IDLE, ATTACKING);
    add_transition(INTERACTED, IDLE, INTERACTING);

    /* to stop*/
    add_transition(STOPPED, WALKING, IDLE);
    add_transition(STOPPED, ATTACKING, IDLE);
    add_transition(STOPPED, INTERACTED, IDLE);

    change_state(IDLE, NONE);

    Environment *env = Environment::get_instance();
    env->events_manager->register_listener(this);
}

Inti::~Inti()
{
    Environment *env = Environment::get_instance();
    env->events_manager->unregister_listener(this);
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

Life*
Inti::life()
{
    return m_impl->life();
}


bool 
Inti::can_change(){
	return m_impl->can_change(); 
}


bool
Inti::on_message(Object *sender, MessageID id, Parameters p)
{
    return m_impl->on_message(sender, id, p);
}

