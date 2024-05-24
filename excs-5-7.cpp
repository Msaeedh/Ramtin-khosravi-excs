#include <iostream>
#include <vector>
using namespace std ;

int excs57(vector<int> vec , int i = 0)
{
	if( i >= vec.size() )
		return 0 ;
	if (i%2)
		return (-1*vec[i]) + excs57(vec , i+1) ;
		return vec[i] + excs57(vec , i+1 ) ;
}

int main ()
{
	vector<int> test { 10,1,10,1,10,1 } ;
	cout << excs57(test) ;
	
	return 0 ;
}