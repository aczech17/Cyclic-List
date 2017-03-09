class CycList
{
    class Node
    {
        friend class CycList;
        Node(int id=0,int val=0) : index(id), value(val) {}
        ~Node();
        int index;
        int value;
        Node *next;
        Node *prev;
        void operator+(Node n);//dodawanie elementow
        void operator/();//usuwanie elementu
        void operator&();//kopiowanie elementu
        void operator<(Node n);
        void operator>(Node n);
        void operator<<();//dostep do elementu
    };
    ~CycList();
public:
    void pushFirst(int value);
    void pushLast(int value);
    void pushAfter(int value,int index);
    void pushBefore(int value,int index);
    void pushIndex(int value, int index);
    void deleteIndex(int index);
    void deleteValue(int value);
    void deleteBetween(int low,int high);
    void deleteAfter(int index);
    void deleteBefore(int index);
    void deleteFirst();
    void deleteLast();
    void NodeValue(int value);
    void NodeIndex(int index);
    void NodeFirst();
    void NodeLast();
    void deleteRepeats();
    int quantity();
    bool isLarger(Node, Node);
    bool operator+(CycList);
    bool operator-(CycList);
};
