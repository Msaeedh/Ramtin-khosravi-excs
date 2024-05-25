

string Date::days_between(Date d)
{
	long total_days = 0 ;
	
	for(int i = 1 ; i < year ; i++)
		total_days += (is_leap_year(i)) ? 366 : 365 ;
	
	for(int i = 1 ; i < month ; i++)
		toatal_days += day_of_month(i , year ) ;
		
	total_days += day ;
	
	switch(total_day % 7)
	{
		case 0 : return "thu" ;
		case 1 : return "fri" ;
		case 2 : return "sat" ;
		case 3 : return "sun" ;
		case 4 : return "mon" ;
		case 5 : return "tue" ;
		case 6 : return "wed" ;
	}
}