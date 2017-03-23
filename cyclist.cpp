#include "cyclist.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
CycList::CycList(Node* firstParam, Node* lastParam)
{
	this->first = firstParam;
	this->last = lastParam;
	lSize = 0;
}
CycList::~CycList()
{
	Node *i = this->first;
	Node *j = NULL;
	if (last) last->next = NULL;
	if (i) j = i->next;
	while (i)
	{
		delete i;
		i = NULL;
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
		first = NULL;
		last = NULL;
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
void CycList::pushIndex(int id, int val)
{
	Node *i = first;
	while (i != last)
	{
		if (i->index == id)
		{
			i->value = val;
			return;
		}
		i = i->next;
	}
	if (last->index == id) last->value = val;
}
void CycList::findToDelete(string param, int var)//delete index or delete value var2=value or index
{
	Node *i = first;
	Node *j = i;
	if(i) do
	{
		if( (param=="index" && i->index==var) || (param=="value" && i->value==var) )
		{
			j = i->next;
			deleteNode(i);
			if (this->quantity() != 0) i = j;
			else j = NULL;
		}
		else
		{
			i = i->next;
			j = i;
		}
	}while (j != first);
}
void CycList::deleteIndex(int id)
{
	findToDelete("index", id);
}
void CycList::deleteValue(int val)
{
	findToDelete("value", val);
}
void CycList::deleteBetween(int low, int high)
{
	Node *i = first;
	Node *j = first;
	if(i) do
	{
		if (i->value >= low && i->value <= high)
		{
			j = i->next;
			deleteNode(i);
			if (this->quantity() != 0) i = j;
			else j = NULL;
		}
		else
		{
			i = i->next;
			j = j->next;
		}
	}while (j != first);
}
void CycList::deleteFirst()
{
	deleteNode(first);
}
void CycList::deleteLast()
{
	deleteNode(last);
}
CycList::Node* CycList::nodeValue(int val)
{
    Node *i=first;
    if(i) do
    {
        if(i->value==val) return i;
        i=i->next;
    }while(i!=first);
    return NULL;
}
CycList::Node* CycList::nodeIndex(int id)
{
    Node *i=first;
    if(i) do
    {
        if(i->index==id) return i;
        i=i->next;
    }while(i!=first);
    return NULL;
}
int CycList::quantity()
{
	return lSize;
}
void CycList::show()
{
	cout << "Index\tValue" << endl;
	Node *i = first;
	if(i) do
    {
        cout<<i->index<<'\t'<<i->value<<endl;
        i=i->next;
    }while(i!=first);
}
bool CycList::operator==(CycList c)
{
    if(this->quantity()!=c.quantity()) return 0;
    if(this->quantity()==0) return 1;
    Node *i=this->first;
    Node *j=c.first;
    do
    {
        if(i->index!=j->index || i->value!=j->value) return 0;
        i=i->next;
        j=j->next;
    }while(i!=this->first);
    return 1;
}
bool CycList::operator<(CycList c)
{
    if(this->quantity()<c.quantity()) return 1;
    return 0;
}
bool CycList::operator>(CycList c)
{
    if(this->quantity()>c.quantity()) return 1;
    return 0;
}
void CycList::operator=(const CycList c)
{
    this->~CycList();
    this->first=NULL;
    this->last=NULL;
    this->lSize=0;
}
CycList CycList::operator+(const CycList c)
{

    CycList a=*this;
    Node *i=c.first;
    if(i) do
    {
        a.pushFirst(i->index,i->value);
        i=i->next;
    }while(i!=c.first);
    return a;
}
