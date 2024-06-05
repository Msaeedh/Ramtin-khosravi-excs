#include <iostream>
#include <vector>

template<typename InputIterator>
int count(InputIterator first , InputIterator last ) {
	int count = 0 ;
	
	while(first != last){
		count++ ;
		first++ ;
	}
	return count ;
}

int main() 
{
	std::vector<int> vec { 1,2,3,4,5,6,7,8,9,10 } ;
	std::cout<< ::count(vec.begin() , vec.end() ) ;
	
	return 0 ;
}