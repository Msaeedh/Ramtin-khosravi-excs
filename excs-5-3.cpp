#include <iostream>
#include <vector>
using namespace std ;

int sum_list (vector<int> list , int i = 0 )
{
	if (list.size() == i)
		return 0 ;
	return list[i] + sum_list(list , i + 1) ;
}

int main ()
{
	vector<int> test { 10,10 ,100,50 ,50 } ;
	cout << sum_list(test) ;
	
	return 0 ;
}