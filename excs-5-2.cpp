#include <iostream> 
using namespace std;

int reverse (int input)
{
	int out = 0 ;
	while (input > 0){
		out = (out*10) + (input %10 ) ;
		input /= 10 ;
	}
	return out ;
//		
//		
//		if(input < 10 )
//			return input ;
//		return (input%10)*10 + reverse(input-= (input%10)) ;
}

int main()
{
	
	cout << "reverse of 123456 : " << reverse(123456) ;
	return 0 ;
}