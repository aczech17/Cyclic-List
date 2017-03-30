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
	a.pushLast(21);
	a.pushLast(37);
	b.pushLast(21);
	b.pushLast(88);
    CycList c=b-a;

	c.show();
}
