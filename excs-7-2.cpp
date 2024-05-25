
int days_between(Date d1, Date d2) {
	if(d1.compare(d2))
	{
		Date tmp = d1 ;
		d1 = d2 ;
		d2 = tmp ;
	}
	
    int count = 1;
    while (!d1.equals(d2)) {
        d1.inc_one_day();
        count++;
    }
    return count;
}	
	