#include <iostream>
#include "cyclist.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{
    CycList c;
    c.pushFirst(1,10);
    c.pushFirst(2,20);
    c.pushFirst(3,30);
    c.show();
    return 0;
}
