#include "cyclist.h"
#include <conio.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	CycList c;
	c.pushLast(1, 1);
	c.pushLast(2, 10);
	c.deleteIndex(1);
	c.deleteIndex(2);
	c.deleteIndex(0);
	c.show();
	cout << "Rozmiar listy = " << c.quantity();
	_getch();
	return 0;
}