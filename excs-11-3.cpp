

class Eq_triangle : public shape {
	public :
		Eq_triangel(int init_x , int init_y , int init_side) ;
	    virtual void scale(int s);
	    virtual void print();
		
	private :
		int side ;
			
};

Eq_triangel::Eq_triangel(int init_x , int init_y , int init_side) 
	: Shape(init_x ,init_y )
{
	if(init_side <= 0 )
		throw IllegalArgumentException() ;
}

void Eq_triangel::scale(int s) {
	side *= s ;
}

void Eq_triangel::print(){
	std::cout << "Eq_triangel : " << x <<','<<y << ',' << side << std::endl ;
}


