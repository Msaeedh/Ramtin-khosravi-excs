#include <iostream>
#include <vector>
#include <string>
using namespace std ;

void reverse (int *number , int count) ;

class bigInt
{
	private :
	int *number ;
	int size ;
	int count ;
	
	void expand() {
		int *newArr = new int[size+10] ;
		for(int i = 0 ; i < count ; i++)
			newArr[i] = number[i] ;
		clear() ;
		number = newArr ;
		size += 10 ;
	}
	
	public :
		bigInt(int value) ;
		bigInt(string s) ;
		~bigInt() ;
		void clear() ;
		bigInt operator= (bigInt b) ;
		bigInt(const bigInt &other) ;
		static void swap(bigInt& b1 , bigInt& b2 ) ;
		bool operator== (bigInt b) ;
		bigInt operator+(const bigInt& other) const ;
		bigInt operator+= (bigInt other) ;
		friend std::ostream& operator<<(std::ostream& os, const bigInt& obj) ;
		
};
	bigInt::bigInt(int value) 
	{
		size = count = 0 ;
		expand() ;
		while(value)
		{
			number[count] = value%10 ;
			value /= 10 ;
			count++ ;
		}
		reverse(number , count ) ;
	}
	
	bigInt::bigInt(string s)
	{
		for(int i = 0 ; i < s.length() ; i++ )
		{
			if(count >= size )
				expand() ;
			number[i] = (s[i] - '0') ;
		}
	}	
	
	bigInt::bigInt (const bigInt &other)
	{
		number = new int[other.size] ;
		size = other.size ;
		for (count = 0 ; count < other.count ; count++)
			number[count] = other.number[count] ;

	}
	
	bigInt bigInt::operator= (bigInt other)
	{
		clear() ;
		number = new int[other.size] ;
		size = other.size ;
		for (count = 0 ; count < other.count ; count++)
			number[count] = other.number[count] ;

		return *this ;
	}
	
		static void swap(bigInt& b1 , bigInt& b2 )
	{
		bigInt tmp = b1 ;
		b1 = b2 ;
		b2 = b1 ;
	}
	
	bool bigInt::operator== (bigInt other)
	{
		if (count != other.count || size != other.size )
			return false ;
		for(int i = 0 ; i < count && i < other.count ; i++)
			if (number[i] != other.number[i])
				return false ;
		
		return true ;
	}
	
	bigInt bigInt::operator+(const bigInt& other) const
    {
        bigInt result(0);

        int carry = 0;
        int i = count - 1;
        int j = other.count - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += number[i];
            if (j >= 0)
                sum += other.number[j];

            result.number[result.count] = (sum % 10);
            carry = sum / 10;

            i--;
            j--;
            result.count++ ;
        }
        reverse(result.number , result.count);
        return result;
	}
	
	void bigInt::clear() {
		if(number != NULL)
			delete[] number ;
	}
	
	bigInt::~bigInt() {
		clear() ;
	}
	    bigInt bigInt::operator+= (bigInt other)
    {
    	*this = *this + other ;
    	return *this ;
	}
    
    std::ostream& operator<<(std::ostream& os, const bigInt& obj)
    {
        for (int i = 0 ; i < obj.count ; i++ )
            os << obj.number[i] <<' ' ;
        return os;
    }
    
void reverse (int *number , int count)
{
	for(int i = 0 ; i < count/2 ; i++ )
	{
		int tmp = number[i] ;
		number[i] = number[count -i -1] ;
		number[count -i -1] = tmp ;
		
	}
}
	

int main()
{
	cout <<"salam1" ;
    bigInt a(12345);
    cout <<"salam" ;
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














