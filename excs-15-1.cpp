#include <iostream>
using namespace std;


class invalid_operation_ex {};

template<typename T>
class stack {
public:
    stack(int size );
    stack(const stack<T>&);
    ~stack();
    stack& operator=(const stack<T>&);
    void push(T x);
    void pop();
    T top() const;
    int elem_count() const { return count; }
private:
    T *elements;
    int size;
    int count;
};

template<typename T>
stack<T>::stack(int s ) {
    cout << "--constructor called\n";
    size = s;
    elements = new T[size];
    count = 0;
}

template<typename T>
stack<T>::stack(const stack<T>& s) {
    cout << "-- copy constructor called\n";
    size = s.size;
    count = s.count;
    elements = new T[size];
    for (int i = 0; i < count; i++)
        elements[i] = s.elements[i];
}

template<typename T>
stack<T>::~stack() {
    cout << "--destructor called\n";
    delete[] elements;
}

template<typename T>
stack<T>& stack<T>::operator=(const stack<T>& s)
{
    if (this == &s)
        return *this;
        
    count = s.count;
    size = s.size;
    delete[] elements;
    elements = new T[size];
    for (int i = 0; i < count; i++)
        elements[i] = s.elements[i];
        
    return *this;
}

template<typename T>
void stack<T>::push(T x) {
    if (count >= size)
        throw invalid_operation_ex();

    elements[count] = x;
    count++;
}

template<typename T>
void stack<T>::pop() {
    if (count > 0)
        count--;
    else
        throw invalid_operation_ex();
}

template<typename T>
T stack<T>::top() const {
    if (count > 0)
        return elements[count-1];
    else
        throw invalid_operation_ex();
}

void print_stack(stack<int> s) {
    while (s.elem_count() > 0) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> u(10);
    u.push(4);
    u.push(5);
    u.push(12);

    stack<int> w(10);
    w = u;
}



















