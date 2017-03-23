#include "cyclist.h"
#include <conio.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	CycList c;
	CycList d;
	for(int i=1;i<=1000000;i++)
        d.pushLast(i,i);
    for(int i=1;i<=1000000;i++)
        c.pushLast(i,i);
	d=c;
    d.show();
	return 0;
}
