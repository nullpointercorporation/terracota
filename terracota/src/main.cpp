#include <iostream>

#include "terracota.h"

using namespace std;

int 
main(int, char** )
{
    try
    {
        Terracota terracota;
        terracota.init("res/conf/settings.conf");
        terracota.run();
    }
    catch (Exception e)
    {
        cerr << e.message() << endl;
        return -1;
    }
    return 0;
}
