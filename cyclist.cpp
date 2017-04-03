#include "cyclist.h"
#include <climits>
CycList::CycList()
{
    lSize = 0;
    sentinel=new Node;
    sentinel->index=-1;
    sentinel->value=-1;
    sentinel->next=sentinel;
    sentinel->prev=sentinel;
    first=sentinel;
    last=sentinel;
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
    delete sentinel;
}
void CycList::assignIndexes()
{
    int id=0;
    Node *i=first;
    while(i && i!=sentinel)
    {
        i->index=id++;
        i=i->next;
    }
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
    Node *tmp=new Node;
    tmp->value=valParam;
    sentinel->next=tmp;
    tmp->prev=sentinel;
    if(lSize==0)
    {
        tmp->next=sentinel;
        sentinel->prev=tmp;
        last=tmp;
    }
    else
    {
        tmp->next=first;
        first->prev=tmp;
    }
    first=tmp;
    lSize++;
    assignIndexes();
}
void CycList::pushLast(int valParam)
{
    Node *tmp=new Node;
    tmp->value=valParam;
    tmp->next=sentinel;
    sentinel->prev=tmp;
    if(lSize==0)
    {
        sentinel->next=tmp;
        tmp->prev=sentinel;
        first=tmp;
    }
    else
    {
        tmp->prev=last;
        last->next=tmp;
    }
    last=tmp;
    lSize++;
    assignIndexes();
}
void CycList::pushAfter(int id, int val)
{
    if(id<0) return;
    Node *i=first;
    if(i==sentinel) return;
    Node *tmp = new Node;
    tmp->value = val;
    while(i->index>=0)
    {
        if(i->index==id)
        {
            tmp->prev=i;
            tmp->next=i->next;
            i->next->prev=tmp;
            i->next=tmp;
            lSize++;
            if(i==last) last=tmp;
        }
        i=i->next;
    }
    assignIndexes();
}
void CycList::pushBefore(int id, int val)
{
    if(id<0) return;
    Node *i=first;
    if(i==sentinel) return;
    Node *tmp=new Node;
    tmp->value=val;
    while(i->index>=0)
    {
        if(i->index==id)
        {
            tmp->next=i;
            tmp->prev=i->prev;
            i->prev->next=tmp;
            i->prev=tmp;
            lSize++;
            if(i==first) first=tmp;
        }
        i=i->next;
    }
    assignIndexes();
}
void CycList::pushIndex(int id, int val)
{
    Node *i = first;
    if(id<0) return;
    while (i->index>=0)
    {
        if (i->index == id)
        {
            i->value = val;
            return;
        }
        i = i->next;
    }
    assignIndexes();
}
void CycList::deleteIndex(int id)
{
    if(id<0) return;
    for(Node *i=first;i->index>=0;i=i->next)
        if(i->index==id)
    {
        deleteNode(i);
        break;
    }
    assignIndexes();
}
void CycList::deleteValue(int val)
{
    Node *i=first;
    while(i->index>=0)
    {
        if(i->value==val)
        {
            i=i->next;
            deleteNode(i->prev);
        }
        else i=i->next;
    }
    assignIndexes();
}
void CycList::deleteBetween(int low, int high)
{
    Node *i=first;
    while(i->index>=0)
    {
        if(i->value>=low && i->value<=high)
        {
            i=i->next;
            deleteNode(i->prev);
        }
        else i=i->next;
    }
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
    while(i->index>=0)
    {
        if(i->value!=j->value) return 0;
        i=i->next;
        j=j->next;
    }
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
    while(i && i->index>=0)
    {
        x.pushLast(i->value);
        i=i->next;
    }
    i=c.first;
    while(i && i->index>=0)
    {
        x.pushLast(i->value);
        i=i->next;
    }
    x.assignIndexes();
    return x;
}

void CycList::operator=(CycList c)
{
    while(this->quantity()>0)
        this->deleteFirst();
    Node *i=c.first;
    while(i && i->index>=0)
    {
        this->pushLast(i->value);
        i=i->next;
    }
    this->assignIndexes();
}
CycList CycList::operator-(const CycList& c)
{
    CycList n;
    Node *i=this->first;
    Node *j=c.first;
    while(i && i->index>=0)
    {
        n.pushLast(i->value);
        i=i->next;
    }
    i=c.first;
    while(i && i->index>=0)
    {
        n.deleteValue(j->value);
        j=j->next;
    }
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
    while(i && i->index>=0)
    {
        if(rep[i->value+x]==0) rep[i->value+x]++;
        else deleteNode(i);
        i=i->next;
    }
    assignIndexes();
    delete [] rep;
}
CycList::Node* CycList::begin()
{
    return first;
}
CycList::Node* CycList::end()
{
    return sentinel;
}
void CycList::iterator::operator=(CycList::Node* n)
{
    i=n;
}
int CycList::iterator::operator*()
{
    if(i) return i->value;
}
void CycList::iterator::operator++()
{
    if(i) i=i->next;
}
void CycList::iterator::operator--()
{
    i=i->prev;
}
bool CycList::iterator::operator==(Node* n)
{
    return this->i == n;
}
bool CycList::iterator::operator!=(Node *n)
{
    return this->i != n;
}
