#include <iostream>
#include <vector>

template<typename InputIterator, typename UnaryPredicate>
int count_if(InputIterator first, InputIterator last, UnaryPredicate pred) {
	
    int count = 0;
    while (first != last) {
        if (pred(*first)) {
            count++;
        }
        ++first;
    }
    return count;
}

bool is_even(int x) {
    return x % 2 == 0;
}

int main() 
{
	std::vector<int> vec { 1,2,3,4,5,6,7,8,9,10 } ;
	std::cout<< ::count_if(vec.begin() , vec.end() , is_even ) ;
	
	return 0 ;
}
















