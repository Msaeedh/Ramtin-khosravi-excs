#include <iostream>
#include <vector>
using namespace std ;

int excs58(vector<int> vec , int i = 0)
{
	if( i >= vec.size() )
		return 0 ;
	if (i+1 < vec.size())
	{
		if((i/2)%2)
			return (-1)*(vec[i]*vec[i+1]) + excs58(vec , i+2) ;
		return (vec[i]*vec[i+1]) + excs58(vec , i+2) ;
	}
	if((i/2)%2)
		return (-1*vec[i]) + excs58(vec , i+1 ) ;
	return vec[i] + excs58(vec , i+1) ;
		
}

int main ()
{
	vector<int> test { 10,2,10,1,13,2 } ;
	cout << excs58(test) ;
	
	return 0 ;
}