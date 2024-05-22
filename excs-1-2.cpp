#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input , res ;
	cout << "Enter as many names as you can : " ;
	res += "[" ;
	while(cin >> input )
	{
		static int index = 0 ; index++ ;
		if(input == "#") break ;
		res = (index != 1)? ", " : "" ;
		res += input ;
	}
	
	res += "]" ;
	cout << res ;
	
	return 0;
}