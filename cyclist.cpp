#include "cyclist.h"
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;
CycList::CycList(Node* firstParam, Node* lastParam, bool lEmptyParam)
{
    this->first=firstParam;
    this->last=lastParam;
    this->lEmpty=lEmptyParam;
}
CycList::~CycList()
{
    Node *i=this->first;
    Node *j;
    if(i && i->next) j=i->next;
    while(i)
    {
        delete i;
        i=i->next;
        if(j) j=j->next;
    }
}
void CycList::pushFirst(int indexParam, int valParam)
{
    Node *tmp=new Node;
    tmp->index=indexParam;
    tmp->value=valParam;
    if(this->lEmpty)
    {
        tmp->next=nullptr;
        tmp->prev=nullptr;
        last=tmp;
    }
    else
    {
        tmp->next=first;
        first->prev=tmp;
        last->next=tmp;
        tmp->prev=last;
    }
    first=tmp;
    this->lEmpty=0;
}
void CycList::show()
{
    cout<<"Index\tValue"<<endl;
    Node *i=first;
    while(i!=last)
    {
        cout<<i->index<<'\t'<<i->value<<endl;
        i=i->next;
    }
    cout<<last->index<<'\t'<<last->value<<endl;
    return;
}
