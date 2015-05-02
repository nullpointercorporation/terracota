#include <iostream>

#include "terracota.h"

using namespace std;

int 
main(int  , char** )
{
    try
    {
        Terracota terracota;
        terracota.init("Terracota",800,600);
        terracota.run();
    }
    catch (Exception e)
    {
        cerr << e.message() << endl;
        return -1;
    }
    return 0;
}
