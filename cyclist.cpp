#include "cyclist.h"

CycList::CycList(Node* firstParam, Node* lastParam)
{
    this->first = firstParam;
    this->last = lastParam;
    lSize = 0;
}
CycList::~CycList()
{
    Node *i = first;
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
    lSize=0;
}
void CycList::assignIndexes()
{
    int id=0;
    Node *i=first;
    if(i) do
    {
        i->index=id++;
        i=i->next;
    }while(i!=first);
}
CycList::Node* CycList::newNode(int valParam)
{
    Node *tmp = new Node;
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
void CycList::pushFirst(int valParam)
{
    first = newNode(valParam);
    if (lSize == 1) last = first;
    assignIndexes();
}
void CycList::pushLast(int valParam)
{
    last = newNode(valParam);
    if (lSize == 1) first = last;
    assignIndexes();
}
void CycList::pushAfter(int id, int val)
{
    Node *tmp = new Node;
    tmp->value = val;
    Node *i=first;
    if(i) do
    {
        if(i->index==id)
        {
            tmp->next=i->next;
            tmp->prev=i;
            i->next->prev=tmp;
            i->next=tmp;
            if(i==last) last=tmp;
            lSize++;
            assignIndexes();
            return;
        }
        i=i->next;
    }while(i!=first);
    assignIndexes();
}
void CycList::pushBefore(int id, int val)
{
    Node *tmp = new Node;
    tmp->value = val;
    if (!first) return;
    if (first->index == id) pushFirst(val);
    else for (Node *i = first->next; i != first; i = i->next)
        {
            if (i->index == id)
            {
                tmp->prev = i->prev;
                tmp->next = i;
                i->prev->next = tmp;
                i->prev = tmp;
                lSize++;
                assignIndexes();
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
    assignIndexes();
}
void CycList::findToDelete(const char param, int var)//delete index or delete value var2=value or index
{
    Node *i = first;
    Node *j = i;
    if(i) do
        {
            if( (param=='i' && i->index==var) || (param=='v' && i->value==var) )
            {
                j = i->next;
                deleteNode(i);
                if (this->quantity() != 0) i = j;
                else j = NULL;
                return;
            }
            else
            {
                i = i->next;
                j = i;
            }
        }
        while (j != first);
}
void CycList::deleteIndex(int id)
{
    findToDelete('i', id);
    assignIndexes();
}
void CycList::deleteValue(int val)
{
    findToDelete('v', val);
    assignIndexes();
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
        }
        while (j != first);
    assignIndexes();
}
void CycList::deleteFirst()
{
    deleteNode(first);
    assignIndexes();
}
void CycList::deleteLast()
{
    deleteNode(last);
    assignIndexes();
}

int CycList::quantity()
{
    return lSize;
}
bool CycList::operator==(CycList& c)
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
    }
    while(i!=this->first);
    return 1;
}
bool CycList::operator<(CycList& c)
{
    if(this->quantity()<c.quantity()) return 1;
    return 0;
}
bool CycList::operator<=(CycList& c)
{
    return this->quantity()<c.quantity() || this->quantity()==c.quantity();
}
bool CycList::operator>(CycList& c)
{
    if(this->quantity()>c.quantity()) return 1;
    return 0;
}
bool CycList::operator>=(CycList& c)
{
    return this->quantity()>c.quantity() || this->quantity()==c.quantity();
}
bool CycList::operator!=(CycList& c)
{
    return !(*this==c);
}
CycList CycList::operator+(const CycList& c)
{
    CycList x;
    Node *i=this->first;
    Node *j=c.first;
    if(i) do
    {
        x.pushLast(i->value);
        i=i->next;
    }while(i!=this->first);
    if(j) do
    {
        x.pushLast(j->value);
        j=j->next;
    }while(j!=c.first);
    x.assignIndexes();
    return x;
}

void CycList::operator=(CycList c)
{
    while(this->quantity()>0)
        this->deleteFirst();
    Node *i=c.first;
    if(i) do
    {
        this->pushLast(i->value);
        i=i->next;
    }while(i!=c.first);
    this->assignIndexes();
}
CycList CycList::operator-(const CycList& c)
{
    CycList n;
    Node *i=this->first;
    Node *j=c.first;
    if(i) do
    {
        n.pushLast(i->value);
        i=i->next;
    }while(i!=this->first);
    if(j) do
    {
        n.deleteValue(j->value);
        j=j->next;
    }while(j!=c.first);
    return n;
}
void CycList::operator+=(const CycList& a)
{
    *this=*this+a;
}
void CycList::operator!()
{
    while(this->quantity()>0)
        this->deleteFirst();
}
void CycList::deleteRepeats()
{
    const int n=1000000000;
    bool *rep=new bool[n]; //[-n/2+1,n/2]
    const int x=n/2-1;
    Node *i=first;
    if(i) do
    {
        if(rep[i->value+x]==0) rep[i->value+x]++;
        else deleteNode(i);
        i=i->next;
    }while(i!=first);
    assignIndexes();
    delete [] rep;
}
int CycList::node(int id)
{
    Node *i=first;
    if(i) do
    {
        if(i->index==id) return i->value;
        i=i->next;
    }while(i!=first);
    return 0;
}
