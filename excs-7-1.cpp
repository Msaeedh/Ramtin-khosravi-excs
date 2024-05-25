

int Date::compare(Date d)
{
	if (equals(d))
		return 0 ;
		
	if(year > d.year){
		return 1 ;
	}
	else if(year == d.year)
	{
		if(month > d.month)
			return 1 ;
			
		else if (month == d.month ) {
			if(day > d.day)
				return 1 ;
		}
	}
		
	return -1 ;
}