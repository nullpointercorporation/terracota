#include <iostream>

#include "terracota.h"

using namespace std;

int 
main(int, char** )
{
    try
    {
        Terracota terracota;
//        terracota.init("terracota", 1067, 600);
        terracota.init("tc.ini");
        terracota.run();
    }
    catch (Exception e)
    {
        cerr << e.message() << endl;
        return -1;
    }
    return 0;
}
