#include <iostream>
#include "game.h"

using namespace std;

int main(){

   Game game("Terracota");

    try
    {
        game.init();
        game.run();
    } catch (Exception ex)
    {
        cerr << ex.message() << endl;
        return -1;
    }

    return 0;
}

