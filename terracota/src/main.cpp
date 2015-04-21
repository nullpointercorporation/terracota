#include "terracota_game.h"

#include <iostream>

using namespace std;

int main()
{
    try
    {
        Terracota terracota;
        terracota.init("Terracota", 640, 480);
        terracota.run();
    } catch (Exception ex)
    {
        cerr << ex.message() << endl;
        return -1;
    }

    return 0;
}

