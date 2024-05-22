#include <iostream>
using namespace std;

#define in_to_cm 2.54

int main()
{
	double in ;
	cout << "Program to convert inches to centimeters " << endl ;
	cout << "Enter a length in inches : " ;
	cin >> in ;
	
	cout << "\n\t" << in*in_to_cm << " cm" ;
	
	return 0;
}