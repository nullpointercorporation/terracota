/*
 * Classe que representa o input a ser utilizado pelo usuário.
 *
 * Autor: Carlos Oliveira
 * Data: 17/04/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

class Input
{
public:
    static Input* Instance();
    void quitGame();
    void handle(SDL_Event &event);
    bool hasQuit();
    static Input* getInstance();
protected:
    void onKeyDown(SDL_Event &event);
    Input(bool done=false);
    Input(Input const&);
    Input& operator=(Input const&);
    ~Input(){};
private:
    bool m_done;
    static Input * instance;
};

#endif
