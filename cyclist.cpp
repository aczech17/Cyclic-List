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
void CycList::deleteNode(Node *n)
{
	if (!n) return;
	n->prev->next = n->next;
	n->next->prev = n->prev;
	if (n == first) first = first->next;
	if (n == last) last = last->prev;
	delete n;
	lSize--;
	if (lSize == 0)
	{
		first = nullptr;
		last = nullptr;
	}
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
void CycList::pushAfter(int id, int idNew, int val)
{
		Node *tmp = new Node;
		tmp->index = idNew;
		tmp->value = val;
		for (Node *i = first; i != last; i = i->next)
		{
			if (i->index == id)
			{
				tmp->next = i->next;
				tmp->prev = i;
				i->next->prev = tmp;
				i->next = tmp;
				lSize++;
				return;
			}//if
		}//for
		if (last && last->index == id) pushLast(idNew, val);
}
void CycList::pushBefore(int id, int idNew, int val)
{
	Node *tmp = new Node;
	tmp->index = idNew;
	tmp->value = val;
	if (!first) return;
	if (first->index == id) pushFirst(idNew, val);
	else for (Node *i = first->next; i != first; i = i->next)
	{
		if (i->index == id)
		{
			tmp->prev = i->prev;
			tmp->next = i;
			i->prev->next = tmp;
			i->prev = tmp;
			lSize++;
			return;
		}
	}
}
void CycList::deleteIndex(int id)
{
	Node *i = first;
	Node *j = i;
	while (j!=last)
	{
		if (i->index == id)
		{
			j = i->next;
			deleteNode(i);
			if (this->quantity() != 0) i = j;
			else j = nullptr;
		}
		else
		{
			i = i->next;
			j = i;
		}
	}
	if (last && last->index == id) deleteNode(last);
}
int CycList::quantity()
{
	return lSize;
}
void CycList::show()
{
	cout << "Index\tValue" << endl;
	Node *i = first;
	while (i && i != last)
	{
		cout << i->index << '\t' << i->value << endl;
		i = i->next;
	}
	if(last) cout << last->index << '\t' << last->value << endl;
	return;
}