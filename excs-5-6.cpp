#include <iostream>
using namespace std ;


bool palindrome2(string text , int L = 0 ,int R= -1 )
{
	R = (R==-1)? text.size() : R ;
	if (L >= R)
		return true ;
	if (!((text[L] >= 'a' && text[L] <= 'z') || 
	(text[L] >= 'A' && text[L] <= 'Z')))
		return palindrome2(text , L+1 , R) ;
		
	if (!((text[R] >= 'a' && text[R] <= 'z') || 
	(text[R] >= 'A' && text[R] <= 'Z')))
		return palindrome2(text , L , R-1) ;
		
	if (text[L] == text[R])
		return palindrome2(text, L+1 , R-1) ;
	
	return false ;
}


int main ()
{
	string test1 = "sal,am" ;
	string test2 = "sa,,,,la.s" ;
	cout << palindrome2(test1) << endl ;
	cout << palindrome2(test2) <<endl ;
	
	return 0 ;
}