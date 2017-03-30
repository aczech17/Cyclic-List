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
	b.pushLast(21);
	b.pushLast(37);
	b.pushLast(21);
	b.pushLast(37);
	b.pushLast(14);
    b.deleteRepeats();

	b.show();
}
