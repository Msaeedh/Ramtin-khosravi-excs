#include <iostream>
using namespace std;

class adding_to_empty_list{} ;
class deleting_from_empty_list{} ;

template<typename T>
class List {
private:
	template<typename t>
    class Node {
    public:
        Node(t d, Node *n = NULL, Node *p = NULL) 
            : data(d), next(n), prev(p) {}

        t data;
        Node *next;
        Node *prev;
    };

public:
    class Iterator {
    public:
    	T this_element() const {
    		return current->data ;
		}
    	void add(T x) {
    		Node<T> *new_node = new Node<T>(x) ;
    		if(current != NULL) {
    			if(current->next != NULL)
	    			current->next->prev = new_node ;
	    		else
	    			_list->_last = new_node ;
	    		new_node->next = current->next ;
    			current->next = new_node ;
    			new_node->prev = current ;
    		} else 
    			throw adding_to_empty_list() ;
    		
		}
        T next_element() {
            T to_be_returned = current->data;
            current = current->next;
            return to_be_returned;
        }
        bool has_more_elements() {
            return current != NULL;
        }
    private:
        Node<T> *current;
		List<T> *_list ;
        Iterator(Node<T>* n , List<T> *l) { current = n; _list = l ;}
        friend class List;
    };

public:
    List();
    ~List();
    void print();
    void push_front(T x);
    void push_back(T x);
    void merge(List<T> &l) ;
    void clear();
    Iterator get_iterator() {
        return Iterator(_head ,this );
    }
private:
    Node<T>* _head;
    Node<T>* _last;
};

template<typename T>
List<T>::List() {
    _head = nullptr;
    _last = nullptr;
}

template<typename T>
void List<T>::print() {
    for (Node<T>* p = _head; p != NULL; p = p->next)
        cout << p->data << ' ';
        
    cout <<endl ;
}

template<typename T>
void List<T>::push_front(T x) {
    Node<T> *new_node = new Node<T>(x);
    new_node->next = _head;
    if (_head != NULL)
        _head->prev = new_node;
    _head = new_node;
    if (_last == NULL)
        _last = new_node;
}

template<typename T>
void List<T>::push_back(T x) {
    if (_head == nullptr)
        push_front(x);
    else {
        Node<T> *new_node = new Node<T>(x);
        new_node->prev = _last;
        _last->next = new_node;
        _last = new_node;
    }
}

template<typename T>
List<T>::~List() {
    clear();
}

template<typename T>
void List<T>::clear() {
    Node<T> *p = _head;
    while (p != nullptr) {
        Node<T> *q = p;
        p = p->next;
        delete q;
    }
    _head = nullptr;
    _last = nullptr;
}

template<typename T>
void List<T>::merge(List<T> &l) {
	List<T>::Iterator it1 = get_iterator() ;
	List<T>::Iterator it2 = l.get_iterator() ;
	
	List<T> result ;
	
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

template<typename T>
class MyList : public List<T> 
{
	public : 
	void remove_last() {
		List<T> new_list ;
		List::Iterato<T> it = this->get_iterator() ;
		if(!it.has_more_elements())
			throw deleting_from_empty_list() ;
		T tmp = it.next_element() ;
		
		while(it.has_more_elements()) {
			new_list.push_back(tmp) ;
			tmp = it.next_element() ;
		}
		
		this->List = new_list ;
		
	}
	
};

int main() {
    List<int> l;
    
    l.push_back(86);
    l.push_front(43);
    l.push_front(12);
    
    l.print() ;
    
    List::Iterator it = l.get_iterator() ;
    it.next_element() ;
    it.add(1000) ;
    
    l.print();
}






















