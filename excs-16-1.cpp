#include<iostream>
#include<cstdlib>
using namespace std;

struct student {
	string name ;
	long long st_code ;
	int grade ;
};

int compare(const void *a ,const void *b){
	long long A = (*(student*) a).st_code ;
	long long B = (*(student*) b).st_code ;
	
	return A - B ;
}

int main()
{
	student students[4] ;
	students[0].st_code = 300000000 ;
	students[1].st_code = 100000000 ;
	students[2].st_code = 200000000 ;
	
	students[0].name = "ahmad" ;
	students[1].name = "ali" ;
	students[2].name = "hasan" ;
	
	students[0].grade = 15 ;
	students[1].grade = 17 ;
	students[2].grade = 19 ;
	
	qsort(students , 3 , sizeof(student) ,compare) ;
	
	cout<< students[0].st_code <<endl ;
	cout<< students[1].st_code <<endl ;
	cout<< students[2].st_code <<endl ;
	
	
	
	return 0 ;
}









