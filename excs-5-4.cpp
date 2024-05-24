#include <iostream>
#include <vector>
using namespace std ;

int pos_number(vector<int> list , int i = 0 )
{
	if (list.size()  == i)
		return 0 ;
	if (list[i] < 0)
		return 0 + pos_number(list , i+1)  ;
	return 1 + pos_number(list , i+1)  ;
}

int main ()
{
	vector<int> test { -10,10 ,-100,50 ,50 } ;
	cout << pos_number(test) ;
	
	return 0 ;
}