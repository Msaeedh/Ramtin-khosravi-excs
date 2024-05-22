#include <iostream> 
using namespace std;

class time {
	private:
	int hour ;
	int minute ;
	
	public : 
	time(int h , int m)
	{
		set(h,m) ;
	}
	time(int h)
	{
		set (h) ;
	}
	
	void set(int h ,int m = 0)
	{
		if(h > 24 || h < 0 || m > 59 || m < 0)
			abort() ;
		hour = h ;
		minute = m ;
	}
	
	void print_time()
	{
		cout<< get() << endl ;
	}
	
	string get()
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
	
	int compare(const time& other)
	{
		if(( other.hour*60 + other.minute) > (hour*60 + minute ))
			return -1 ;
		if(( other.hour*60 + other.minute) == (hour*60 + minute ))
			return 0 ;
		//if(( other.hour*60 + other.minute) < (hour*60 + minute ))
		else
			return 1 ;
	}
	
	string time_of_day()
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
	
};

int main()
{
	time t1(20,59) ;
	cout << t1.get() << endl  << t1.time_of_day() << endl;
	t1.print_time() ;
	
	time t2(20) ;
	cout <<t2.get() << endl << t1.compare(t2) ;
	
	return 0;
}



