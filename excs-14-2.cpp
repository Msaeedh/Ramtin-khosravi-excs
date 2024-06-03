#include <iostream>
using namespace std;

class List {
private:
    class Node {
    public:
        Node(int d, Node *n = NULL, Node *p = NULL) 
            : data(d), next(n), prev(p) {}

        int data;
        Node *next;
        Node *prev;
    };

public:
    class Iterator {
    public:
        int next_element() {
            int to_be_returned = current->data;
            current = current->next;
            return to_be_returned;
        }
        bool has_more_elements() {
            return current != NULL;
        }
    private:
        Node *current;
        Iterator(Node* n) { current = n; }
        friend class List;
    };

public:
    List();
    ~List();
    bool search_r(int x , List::Iterator it = 0) ;
    bool search(int x) ; // helper function 
    void print();
    void push_front(int x);
    void push_back(int x);
    void clear();
    Iterator get_iterator() {
        return Iterator(_head);
    }
private:
    Node* _head;
    Node* _last;
};

List::List() {
    _head = NULL;
    _last = NULL;
}

void List::print() {
    for (Node* p = _head; p != NULL; p = p->next)
        cout << p->data << ' ';
}

void List::push_front(int x) {
    Node *new_node = new Node(x);
    new_node->next = _head;
    if (_head != NULL)
        _head->prev = new_node;
    _head = new_node;
    if (_last == NULL)
        _last = new_node;
}

void List::push_back(int x) {
    if (_head == NULL)
        push_front(x);
    else {
        Node *new_node = new Node(x);
        new_node->prev = _last;
        _last->next = new_node;
        _last = new_node;
    }
}

List::~List() {
    clear();
}

void List::clear() {
    Node *p = _head;
    while (p != NULL) {
        Node *q = p;
        p = p->next;
        delete q;
    }
    _head = NULL;
    _last = NULL;
}

bool List::search(int x) 
{
	return search_r(x , this->get_iterator()) ;
		
}
bool List::search_r(int x , List::Iterator it ) 
{
	if(it.has_more_elements()) {
		if(it.next_element() == x )
			return true ;
	} else
		return false ;
	
	return search_r(x , it) ;
			
}

int main() {
    List l;
    
    l.push_back(86);
    l.push_front(43);
    l.push_front(12);
    
    l.print();
    
	cout<< endl << l.search(12) <<endl  ;
        
}
















