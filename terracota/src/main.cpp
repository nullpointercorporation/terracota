#include "terracota.h"

#include <iostream>

using namespace std;

int main()
{
    try
    {
        Terracota terracota;
        terracota.init("Terracota", 800, 600);
        terracota.run();
    } catch (Exception ex)
    {
        cerr << ex.message() << endl;
        return -1;
    }

    return 0;
}

