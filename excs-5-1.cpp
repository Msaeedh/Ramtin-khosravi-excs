#include <iostream> 
using namespace std;

int sum_of_n (int input)
{
	int sum = 0 ;
	while(input > 0)
	{
		sum += input % 10 ;
		input /= 10 ;
	}
	return sum ;
}

int rec_sum_of_n (int input)
{
	if(input < 1 )
		return 0 ;
	return  (input % 10) + rec_sum_of_n(input/10) ;
}

int main()
{
	int test ;
	cout <<" Enter a number : " ;
	cin >> test ;
	cout <<endl << "sum_of_n output : " << sum_of_n(test) ;
	cout <<endl<< "rec_sum_of_n output : " << rec_sum_of_n(test) ;
	
	return 0 ;
}