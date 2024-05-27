#include <vector>
#include <iostream>
using namespace std;

class poly {
	vector<double> vec ;
	int degree ;
	
	public :
		poly(const vector<double>& _vec , int _degree ) ;
		poly operator+ (const poly& other) const ;
		poly operator* (const poly& other) const ;
		poly derivative() ;
		double operator() (double x) const ;
		
};

	poly::poly( const vector<double>& _vec , int _degree )
	{
		if(degree < 0 )
			abort() ;
		vec = _vec ;
		degree = _degree ;
	}
	
	poly poly::operator+(const poly& other) const
	{
		vector<double> result(max(vec.size(),other.vec.size()) , 0.0 ) ;
		
		for(int i = 0 ; i < result.size() ; i++)
		{
			result[i] += (i > degree )? 0.0 : vec.at(i) ;
			result[i] += (i > other.degree)? 0.0 : other.vec.at(i) ;
		}
		return poly(result , result.size() -1) ;
	}
	
	poly poly::operator*(const poly& other) const
	{
		vector<double> result(vec.size() + other.vec.size() - 1 , 0.0 ) ;
		
		for(int i = 0 ; i < vec.size() ; i++)
		{
			for(int j = 0 ; j < other.vec.size() ; j++)
			{
				result[i+j] += ( vec[i] * other.vec[j] ) ;
			}
		}
		
		return poly(result , degree + other.degree ) ;
	}
	
	poly poly::derivative() 
	{
		vector<double> result(vec.size()-1) ;
		
		for(int i = 1 ; i < vec.size() ; i++)
		{
			result[i-1] = vec[i] * i ; 
		}
		
		return poly(result , degree-1 ) ;
	}
	
	double poly::operator() (double x) const
	{
		double sum = 0.0 ;
		
		for(int i = 0 ; i < vec.size() ; i++)
		{
			double pow = 1.0 ;
			for(int j = 0 ; j != i ; j++)
				pow *= x ;
			
			sum += (vec[i] * pow ) ;
		}
		
		return sum ;
	}




int main ()
{
	std::vector<double> a1 = {1.0, 2.0, 3.0} ;
    poly a(a1, 2) ;

    std::vector<double> b1 = {4.0, 5.0} ;
    poly b(b1, 1) ;

    poly sum = a + b;
    poly product = a * b;

    std::cout << "a + b: " << sum(2.0) << std::endl ;
    std::cout << "a * b: " << product(2.0) << std::endl ;
	
    poly a_derivative = a.derivative();
    std::cout << "a' = " << a_derivative(2.0) << std::endl;
	
	return 0 ;
}


















