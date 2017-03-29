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
//	a.pushLast(1,1);
//	a.pushLast(2,2);
//	a.pushLast(3,3);
//	a.pushLast(4,4);


    b.pushLast(1,4);
	b.pushLast(8,8);
	b.pushLast(2,1);
	b.pushLast(3,7);
    b.pushLast(1,2);

	CycList c=a-b;
	!c;
	c.show();
}
