#include <iostream> 
#include <math.h>
using namespace std;

// Helper function to calculate the number of digits in an integer
int numDigits(int num) {
    int count = 0;
    while (num > 0) {
        num /= 10;
        count++;
    }
    return count;
}

int reverse(int input) {
    if (input < 10) {
        return input; // Base case: single-digit number
    }
    int lastDigit = input % 10;
    int remainingDigits = input / 10;
    return (lastDigit * pow(10, numDigits(remainingDigits))) + reverse(remainingDigits);
}

int main()
{
	
	cout << "reverse of 123456 : " << reverse(123456) ;
	return 0 ;
}













