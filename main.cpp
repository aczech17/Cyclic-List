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
	b.pushLast(14);
	b.pushLast(88);
    a+=b;

	a.show();
}
