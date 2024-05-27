#include <iostream>
#include <vector>
#include <string>
using namespace std ;

void reverse (vector<int>& vec)
{
	for(int i = 0 ; i < vec.size()/2 ; i++ )
	{
		int tmp = vec[i] ;
		vec[i] = vec[vec.size() -i -1] ;
		vec[vec.size() -i -1] = tmp ;
	}
}

class bigInt
{
	private :
	vector<int> number ;
	
	public :
		bigInt(int value) ;
		bigInt(string s) ;
		bigInt operator= (bigInt b) ;
		static void swap(bigInt& b1 , bigInt& b2 ) ;
		bool operator== (bigInt b) ;
		bigInt operator+(const bigInt& other) const ;
		bigInt operator+= (bigInt other) ;
		friend std::ostream& operator<<(std::ostream& os, const bigInt& obj) ;
		
};
	bigInt::bigInt(int value) 
	{
		while(value)
		{
			number.push_back(value%10) ;
			value /= 10 ;
		}
		reverse(number) ;
	}
	
	bigInt::bigInt(string s)
	{
		for(int i = 0 ; i < s.size() ; i++ )
		{
			number.push_back(s[i] - '0') ;
		}
	}	
	
	bigInt bigInt::operator= (bigInt b)
	{
		number = b.number ;
		return *this ;
	}
	
	static void swap(bigInt& b1 , bigInt& b2 )
	{
		bigInt tmp = b1 ;
		b1 = b2 ;
		b2 = b1 ;
	}
	
	bool bigInt::operator== (bigInt b)
	{
		return number == b.number ;
	}
	
	bigInt bigInt::operator+(const bigInt& other) const
    {
        bigInt result(0);

        int carry = 0;
        int i = number.size() - 1;
        int j = other.number.size() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += number[i];
            if (j >= 0)
                sum += other.number[j];

            result.number.push_back(sum % 10);
            carry = sum / 10;

            i--;
            j--;
        }
        reverse(result.number);
        return result;
	}
	        
    bigInt bigInt::operator+= (bigInt other)
    {
    	*this = *this + other ;
    	return *this ;
	}
    
    std::ostream& operator<<(std::ostream& os, const bigInt& obj)
    {
        for (int i = 0 ; i < obj.number.size() ; i++ )
            os << obj.number[i];
        return os;
    }


int main()
{
    bigInt a(12345);
    bigInt b("6789");
    
    std::cout << "a: " << a << endl ;
    std::cout << "b: " << b << endl ;
    
	bigInt c = a + b;
	b += a ;
    
    std::cout << "a: " << a << endl ;
    std::cout << "b: " << b << endl ;
    std::cout << "c: " << c << endl ;

    return 0;
}














