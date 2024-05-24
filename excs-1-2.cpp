#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input , res ;
	cout << "Enter as many names as you can : " ;
	cin>> input ;
	res += "[" + input ;
	while(cin >> input )
	{
		res += ", " ;
		res += input ;
	}
	
	res += "]" ;
	cout << res ;
	
	return 0;
}