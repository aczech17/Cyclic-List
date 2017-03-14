#include "cyclist.h"
#include <conio.h>
#include <iostream>
using std::cin;
using std::cout;
int main()
{
	CycList c;
	c.pushFirst(2, 2);
	c.pushFirst(1, 1);
	c.pushLast(3, 3);
	c.show();
	cout << "Rozmiar listy = " << c.quantity();;
	_getch();
	return 0;
}