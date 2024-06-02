#include <iostream>
#include <string>
using namespace std;


class bigInt
{
private:
    int *number;
    int size;
    int count;
    
	void reverse()
	{
	    for (int i = 0; i < count / 2; i++)
	    {
	        int tmp = number[i];
	        number[i] = number[count - i - 1];
	        number[count - i - 1] = tmp;
	    }
	}

    void expand()
    {
        int *newArr = new int[size + 10];
        for (int i = 0; i < count; i++)
            newArr[i] = number[i];
        clear();
        number = newArr;
        size += 10;
    }

public:
    bigInt(int value);
    bigInt(string s);
    ~bigInt();
    void clear();
    bigInt operator=(const bigInt &other);
    bigInt(const bigInt &other);
    static void swap(bigInt &b1, bigInt &b2);
    bool operator==(const bigInt &other);
    bigInt operator+(const bigInt &other) const;
    bigInt operator+=(const bigInt &other); // Added operator+=
    friend std::ostream &operator<<(std::ostream &os, const bigInt &obj);
};

bigInt::bigInt(int value) : number(0) , size(0) , count(0)
{
    expand();
    while (value)
    {
        number[count] = value % 10;
        value /= 10;
        count++;
    }
    reverse();
}

bigInt::bigInt(string s) : number(0) , size(0) , count(0)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (count >= size)
            expand();
        number[i] = (s[i] - '0');
        count++ ;
    }
}

bigInt::bigInt(const bigInt &other)
{
    number = new int[other.size];
    size = other.size;
    for (count = 0; count < other.count; count++)
        number[count] = other.number[count];
}

bigInt bigInt::operator=(const bigInt &other)
{
	if (this == &other)
		return *this ;
    clear();
    number = new int[other.size];
    size = other.size;
    for (count = 0; count < other.count; count++)
        number[count] = other.number[count];
    return *this;
}

void bigInt::swap(bigInt &b1, bigInt &b2)
{
    bigInt tmp = b1;
    b1 = b2;
    b2 = tmp; // Corrected swap
}


bigInt bigInt::operator+(const bigInt &other) const
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
        result.count++;
    }
    result.reverse();
    return result;
}

void bigInt::clear()
{
    if (number == 0) 
    	return ;
    delete[] number;
}

bigInt::~bigInt()
{
    clear();
    size = count = 0 ;
}

bigInt bigInt::operator+=(const bigInt &other)
{
    *this = *this + other;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const bigInt &obj)
{
    for (int i = 0; i < obj.count; i++)
        os << obj.number[i] ;
    return os;
}

bool bigInt::operator==(const bigInt &other)
{
    if (count != other.count || size != other.size)
        return false;
    for (int i = 0; i < count && i < other.count; i++)
        if (number[i] != other.number[i])
            return false;
    return true;
}
	

int main()
{
    bigInt a(12345);
    bigInt b("6789");

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    bigInt c = a + b;
    b += a;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;

    return 0;
}



















