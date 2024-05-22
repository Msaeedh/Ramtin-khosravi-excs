#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<char> alphabet(26) ;
	
	// this can not be done in one step
	
	for(int i = 0 ; i < 26 ; i++)
	{
		alphabet[i] = ('A' + i) ;
	}
	
//	for(int i = 0 ; i < 26 ; i++)
//	{
//		cout << alphabet[i] ;
//	}
	
	
	
	
	return 0 ;
}