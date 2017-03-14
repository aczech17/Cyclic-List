#include "cyclist.h"
#include <iostream>
using std::cout;
using std::endl;
CycList::CycList(Node* firstParam, Node* lastParam)
{
	this->first = firstParam;
	this->last = lastParam;
	lSize = 0;
}
CycList::~CycList()
{
	Node *i = this->first;
	Node *j = nullptr;
	if (last) last->next = nullptr;
	if (i) j = i->next;
	while (i)
	{
		delete i;
		i = nullptr;
		if (j)
		{
			i = j;
			j = j->next;
		}
	}
}
CycList::Node* CycList::newNode(int indexParam, int valParam)
{
	Node *tmp = new Node;
	tmp->index = indexParam;
	tmp->value = valParam;
	if (lSize==0)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->next = first;
		first->prev = tmp;
		last->next = tmp;
		tmp->prev = last;
	}
	lSize++;
	return tmp;
}
void CycList::pushFirst(int indexParam, int valParam)
{
	first = newNode(indexParam, valParam);
	if (lSize == 1) last = first;
}
void CycList::pushLast(int indexParam, int valParam)
{
	last = newNode(indexParam, valParam);
	if (lSize == 1) first = last;
}
int CycList::quantity()
{
	return lSize;
}
void CycList::show()
{
	cout << "Index\tValue" << endl;
	Node *i = first;
	while (i != last)
	{
		cout << i->index << '\t' << i->value << endl;
		i = i->next;
	}
	cout << last->index << '\t' << last->value << endl;
	return;
}