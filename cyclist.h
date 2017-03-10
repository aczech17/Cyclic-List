class CycList
{
    class Node
    {
        friend class CycList;
        int index;
        int value;
        Node(int val=0,int id=0) : index(id), value(val) {}
        //~Node();
        Node *next;
        Node *prev;
        Node operator+(Node n);
    };//Node
    Node *first;
    Node *last;
    bool lEmpty;
public:
    ~CycList();
    CycList(Node* firstParam=nullptr,Node* lastParam=nullptr, bool lEmp=1);
    void pushFirst(int idNew, int val);//id of new node, value of new node
    void pushLast(int idNew, int val);//id of new node, value of new node
    void pushAfter(int id, int idNew, int val);//id of previous node, id of new node, value of new node
    void pushBefore(int id,int idNew, int val);
    void pushIndex(int val, int id);
    void deleteIndex(int id);
    void deleteValue(int val);
    void deleteBetween(int low,int high);
    //void deleteAfter(int id);
    //void deleteBefore(int id);
    void deleteFirst();
    void deleteLast();
    void NodeValue(int value);
    void NodeIndex(int id);
    void deleteRepeats();
    int quantity();
    void show();
    bool operator+(CycList);
    bool operator-(CycList);
    void operator<<(Node n);//dostep do elementu
    void operator/(int id);//usuwanie elementu
    void operator&(Node n);//kopiowanie elementu
    void operator<(Node n);
    void operator>(Node n);
};
