#include <iostream> 
using namespace std;

class time {
	private:
	int hour ;
	int minute ;
	
	public : 
	time(int h , int m) ;
	time(int h) ;
	void set(int h ,int m = 0 ) ;
	void print_time() ;
	string get() ;
	int get_h() ;
	int get_m() ;
	int compare(const time& other) ;
	string time_of_day() ;
	
};

time::time(int h , int m)
{
	set(h,m) ;
}
time::time(int h)
{
	set (h) ;
}

void time::set(int h ,int m)
{
	if(h > 24 || h < 0 || m > 59 || m < 0)
		abort() ;
	hour = h ;
	minute = m ;
}

void time::print_time()
{
	cout<< get() << endl ;
}

string time::get()
{
	string res ;
	res += (hour < 10)? "0" : "" ;
	res += to_string(hour) ;
	
	res += ":" ;
	
	res += (minute < 10)? "0" : "" ;
	res += to_string(minute) ;
	
	//res << to_string(hour) << ":" << minute ;
	return res ;
}

int time::compare(const time& other)
{
	if(( other.hour*60 + other.minute) > (hour*60 + minute ))
		return -1 ;
	if(( other.hour*60 + other.minute) == (hour*60 + minute ))
		return 0 ;
	//if(( other.hour*60 + other.minute) < (hour*60 + minute ))
	else
		return 1 ;
}

string time::time_of_day()
{
	if(hour >= 0 &&  hour < 12)
		return "morning" ;
	if(hour == 12 &&  minute == 0)
		return "noon" ;
	if(hour >= 12 &&  hour < 17)
		return "after noon" ;
	if(hour >= 17 &&  hour < 20)
		return "enening" ;
	else 
		return "night" ;
}

int time::get_h()
{
	return hour ;
}

int time::get_m()
{
	return minute ;
}



int main()
{
	time t1(20,59) ;
	cout << t1.get() << endl  << t1.time_of_day() << endl;
	t1.print_time() ;
	
	time t2(20) ;
	cout <<t2.get() << endl << t1.compare(t2) ;
	
	return 0;
}










