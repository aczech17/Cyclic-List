#include "cyclist.h"
#include <conio.h>
#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	CycList a,b;


    b.pushLast(2,8);
    b.pushLast(3,8);
    b.pushLast(1,2);
    b.pushLast(6,8);
    b.pushLast(21,2);
    b.pushLast(8,9);
    b.deleteRepeats();

	b.show();
}
