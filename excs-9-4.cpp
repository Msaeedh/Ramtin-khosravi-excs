#include <iostream> 
using namespace std;

class Rational{
	private :
		int numerator ;
		int denominator ;
	public :
		Rational(int num, int denom) ;
		Rational(double num) ;
		Rational operator+(const Rational& other) const  ;
		Rational operator+ (const double& number ) const ;
		Rational operator+= (const Rational& other) ;
		Rational operator* (const Rational& other) const ;
		Rational operator*= (const Rational& other) ;
		Rational operator* (const double& num) const ;
		Rational operator*= (const double& num) ;
		Rational operator- (const Rational& other) const ;
		Rational operator- (const double& num) const ;
		Rational operator-= (const Rational& other) ;
		Rational operator-= (const double& num) ;
		Rational operator/ (const Rational& other) const ;
		Rational operator/ (const double& num) const ;
		Rational operator/= (const Rational& other) ;
		Rational operator/= (const double& num) ;
		bool operator== (const Rational& other) const ;
		Rational operator= (const Rational& other) ;
		string get() const ;
		

		
};
Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {
	if (denominator == 0) {
    	cout<<"Denominator cannot be zero.";
    	abort();
	}
}
Rational::Rational(double num) : numerator(num) , denominator(1) {}

Rational Rational::operator+(const Rational& other) const 
{
	int common_denom ;
	if(denominator == other.denominator)
		common_denom = denominator ;
	else
    	common_denom = denominator * other.denominator;
    int new_num = numerator * other.denominator + other.numerator * denominator;
    return Rational(new_num, common_denom);
}

Rational Rational::operator+ (const double& number ) const
{
	return Rational(numerator+(denominator*number) , denominator) ;
}


Rational Rational::operator+= (const Rational& other)
{
	*this = *this + other ;
	return *this ;
}

Rational Rational::operator* (const Rational& other) const
{
	return Rational (numerator*other.numerator , denominator*other.denominator) ;
}

Rational Rational::operator*= (const Rational& other)
{
	return *this = *this *other ;
}

Rational Rational::operator* (const double& num) const
{
	return Rational (numerator * num , denominator) ;
}

Rational Rational::operator*= (const double& num)
{
	return *this = *this * num ;
}

Rational Rational::operator- (const Rational& other) const
{
	int common_denom ;
	if(denominator == other.denominator)
		common_denom = denominator ;
	else
		common_denom = denominator * other.denominator;
    int new_num = numerator * other.denominator - other.numerator * denominator;
    return Rational(new_num, common_denom);
}

Rational Rational::operator- (const double& num) const
{
	return Rational(numerator-(denominator*num) , denominator) ;
}

Rational Rational::operator-= (const Rational& other)
{
	return *this = *this - other ;
}

Rational Rational::operator-= (const double& num)
{
	return *this = *this - num ;
}

Rational Rational::operator/ (const Rational& other) const
{
	return Rational(numerator/other.numerator , denominator/other.denominator) ;
}

Rational Rational::operator/ (const double& num) const
{
	return Rational (numerator/num , denominator) ;
}

Rational Rational::operator/= (const Rational& other)
{
	return *this = *this / other ;
}

Rational Rational::operator/= (const double& num) 
{
	return *this = *this - num ;
}

bool Rational::operator== (const Rational& other) const
{
	return numerator == other.numerator && denominator == other.denominator ;
}

Rational Rational::operator= (const Rational& other)
{
	numerator = other.numerator ;
	denominator = other.denominator ;
	return *this ;
}

string Rational::get() const
{
	string res ;
	res += to_string(numerator) ;
	res += "/" ;
	res += to_string(denominator) ;
	res += " " ;
	return res ;
}
		


ostream& operator<< (ostream& out ,const Rational& r) 
{
	out << r.get() ;
	return out ;
}
		
Rational operator+ (const double& number , const Rational& R ) 
{
	return R+number ;
}

int main()
{
	Rational R1(17,3) ;
	Rational R2(2,3) ;
	Rational R3(0) ;
	
	cout << "R1: "<< R1 <<", R2: "<<R2 <<endl ;
	R3 = (R2 + R1) ;
	cout << "R3 (R1+R2) : "<< R3 ;//<<((R1+R2)==R3)? 1:0 ;
	
	
	return 0 ;
}










