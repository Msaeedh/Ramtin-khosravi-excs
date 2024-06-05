#include <iostream>
#include <vector>

template<typename InputIterator>
int count_if(InputIterator first , InputIterator last , bool (func_ptr)(*InputIterator) ) {
	int count = 0 ;
	
	while(first != last){
		if(func_ptr(*first))
			count++ ;
		first++ ;
	}
	return count ;
}

bool test_func(int a) {
	return (a)%2 ;
}

int main() 
{
	std::vector<int> vec { 1,2,3,4,5,6,7,8,9,10 } ;
	std::cout<< ::count_if(vec.begin() , vec.end() , &test_func ) ;
	
	return 0 ;
}