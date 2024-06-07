#include <iostream>
#include <string>
#include <vector>
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



class organization {
	public :
	organization(int organization_number , int s_emps_number , int h_emps_number 
	, int _h_salary,int s_salary  );
	void add_h_emp(string name , string nat_code ,int  h_salary) ;
	void add_s_emp(string name , string nat_code ,int  s_salary ) ;
	void set_hourly_salary (int hourly_salary);
	void set_stable_salary (int stable salary);
	void set_worked_hours ()
	void set_worked_hours () // use polymorphism these two
	
		
		
	private :
	int h_salary ;
	int s_salary ;
	vector<organization*> sub_orgs ;
	vector<st_emploee*> s_emps ;
	vector<hourly_paid_emp*> h_emps ;
	vector<int> s_emps_worked_hours ;
	vector<int> h_emps_worked_hours ;
	
};

organization::organization(int organization_number , int s_emps_number , int h_emps_number ,
int _h_salary,int s_salary )
	: sub_orgs(organization_number) ,
	s_emps(s_emps_number) ,
	h_emps(h_emps_number) ,
	s_salary(_s_salary) ,
	h_salary(_hsalary)
{
	for(int i = 0 ; i < organization_number ; i++)
		sub_orgs[i] = new organization(0,0,0,h_salary , s_salary ) ;
}

int main()
{
//	st_emploee emp1("hasan" , "12345678" , 14000000) ;
//	hourly_paid_emp emp2("hossein" , "87654321" , 120000 );
//	cout<< emp1.earnings(141) <<endl ;
//	cout<< emp2.earnings(200) <<endl ;
	
	
	return 0 ;
}















