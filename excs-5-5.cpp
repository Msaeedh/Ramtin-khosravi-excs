#include <iostream>
using namespace std ;

bool palindrome(string text , int i = 0)
{
	if ( i > text.size() / 2)
		return true ;
	if (text[i] == text[text.size() - i - 1])
		return palindrome(text , i+1) ;
	return false ;
}


int main ()
{
	string test1 = "salam" ;
	string test2 = "salas" ;
	cout << palindrome(test1) << endl ;
	cout << palindrome(test2) <<endl ;
	
	return 0 ;
}