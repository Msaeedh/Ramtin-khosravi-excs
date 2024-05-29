#include <iostream>
#include <string>
using namespace std ;

class Emploee {
	public : 
	Emploee(string _name , string nat_code ) ;
	virtual int earnings(int hours) = 0 ;
	string get_name() ;
	string get_nat_code() ;
	
	
	private :
	string name ;
	string nat_code ;
	
	
};

Emploee::Emploee(string _name , string _nat_code ) 
	: name(_name) ,
		nat_code(_nat_code)
{
	
}

string Emploee::get_nat_code(){
	return nat_code ;
} 

string Emploee::get_name() {
	return name ;
} 

class hourly_paid_emp : public Emploee {
	public : 
	hourly_paid_emp(string name , string nat_code ,int _hourly_salary) ;
	virtual int earnings(int hours) ;
	
	private :
	int hourly_salary ;
};

hourly_paid_emp::hourly_paid_emp(string name ,string nat_code , int _hourly_salary)
	: Emploee(name , nat_code) ,
		hourly_salary(_hourly_salary)
{}
int hourly_paid_emp::earnings(int hours)
{
	return hourly_salary * hours ;
}

class st_emploee : public Emploee {
	public :
	st_emploee(string name , string nat_code , int _salary ) ;
	virtual int earnings (int hours) ;
	
	private :
	int salary ;
	
};

st_emploee::st_emploee(string name ,string nat_code , int _salary)
	: Emploee(name , nat_code) ,
		salary(_salary)
{ }

int st_emploee::earnings(int hours){
	int hourly_salary = salary/140 ;
	return salary + ((hours-140)*hourly_salary );
}

int main()
{
	st_emploee emp1("hasan" , "12345678" , 14000000) ;
	hourly_paid_emp emp2("hossein" , "87654321" , 120000 );
	cout<< emp1.earnings(141) <<endl ;
	cout<< emp2.earnings(200) <<endl ;
	
	
	return 0 ;
}















