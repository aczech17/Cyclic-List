#ifndef CYC_LIST
#define CYC_LIST
#include <iostream>
class CycList
{
	class Node
	{
		friend class CycList;
		int index;
		int value;
		Node(int val = 0, int id = 0) : index(id), value(val) {}
		//~Node();
		Node *next;
		Node *prev;
	};//Node
	Node *first;
	Node *last;
	int lSize;
	Node* newNode(int valParam);
	void deleteNode(Node*);
	void findToDelete(const char param, int var);
public:
	~CycList();
	CycList(Node* firstParam = NULL, Node* lastParam = NULL);
	void assignIndexes();
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
	Node* nodeValue(int val);//pobranie z listy elementu o okreœlonej wartoœci
	Node* nodeIndex(int id);//--------------||------------ o okreœlonym indeksie
	void deleteRepeats();
	int quantity();
	void operator=(CycList);
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
	int node(int);
	int end();
};
#endif
