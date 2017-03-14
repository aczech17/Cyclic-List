#include "cyclist.h"
#include <conio.h>
int main()
{
	CycList c;
	for (int i = 1; i <= 100; i++)
	{
		c.pushFirst(i, i*i);
	}
	c.show();
	_getch();
	return 0;
}