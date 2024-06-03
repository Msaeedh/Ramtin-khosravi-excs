#include <iostream>
using namespace std;

class adding_to_empty_node{} ;

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
    	int this_element() const {
    		return *current ;
		}
    	void add(int x) {
    		Node *new_node = new Node(x) ;
    		if(current != NULL) {
    			if(current->next != NULL)
	    			current->next->prev = new_node ;
	    		else
	    			_list->_last = new_node ;
	    		new_node->next = current->next ;
    			current->next = new_node ;
    			new_node->prev = current ;
    		} else 
    			throw adding_to_empty_node() ;
    		
		}
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
		List *_list ;
        Iterator(Node* n , List *l) { current = n; _list = l ;}
        friend class List;
    };

public:
    List();
    ~List();
    void print();
    void push_front(int x);
    void push_back(int x);
    void clear();
    Iterator get_iterator() {
        return Iterator(_head ,this );
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
        
    cout <<endl ;
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

void List::merge(List &l) {
	List::Iterator it1 = get_iterator() ;
	List::Iterator it2 = l.get_iterator() ;
	
	List result ;
	
	while(it2.has_more_elements())
	{
		while(it1.has_more_elements()) {
			if(it1.this_element() >= it2.this_element())
				result.push_back(it2.next_element()) ;
			else
				result.push_back(it1.next_element()) ;
		}
	}
	
	clear() ;
	*this = result ;
}

int main() {
    List l;
    
    l.push_back(86);
    l.push_front(43);
    l.push_front(12);
    
    l.print() ;
    
    List::Iterator it = l.get_iterator() ;
    it.next_element() ;
    it.add(1000) ;
    
    l.print();
}






















