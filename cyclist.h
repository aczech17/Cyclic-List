#ifndef CYC_LIST
#define CYC_LIST
#include <iostream>
class CycList
{
    int lSize;
	class Node
	{
		friend class CycList;
		friend class iterator;
		int index;
		int value;
		Node(int id = 0, int val = 0) : index(id), value(val) {}
		Node *next;
		Node *prev;
	};//Node
	Node *first;
	Node *last;
	Node *sentinel;
	void deleteNode(Node*);
	void assignIndexes();
public:
	~CycList();
	CycList();
	Node* begin();
	Node* end();
	void pushFirst(int val);//id of new node, value of new node
	void pushLast(int val);//id of new node, value of new node
	void pushAfter(int id, int val);//id of previous node, id of new node, value of new node
	void pushBefore(int id, int val);
	void pushIndex(int id, int val);//wstawienie w miejsce wyznaczone przez indeks
	void deleteIndex(int id);
	void deleteValue(int val);
	void deleteBetween(int low, int high);
	void deleteFirst();
	void deleteLast();
	void deleteRepeats();
	int quantity();
	CycList operator=(CycList);
	CycList operator+(const CycList&);
	CycList operator-(const CycList&);
	void operator+=(const CycList&);
	bool operator<(CycList&);
	bool operator<=(CycList& c);
	bool operator>(CycList&);
	bool operator>=(CycList& c);
	bool operator==(CycList&);
	bool operator!=(CycList&);
	void operator!();
	class iterator
	{
	    Node *i;
    public:
	    void operator=(Node*);
	    int operator*();
	    void operator++();
	    void operator--();
	    bool operator==(Node*);
	    bool operator!=(Node*);
	};
};
#endif
